#include "KubernetesCluster.hpp"
#include "CloudExceptions.hpp"

void KubernetesCluster::addNode(shared_ptr<Server> server)
{
    nodes_.push_back(server);
}

bool KubernetesCluster::removePod(const string &name)
{
    for (auto it = pods_.begin(); it != pods_.end(); it++)
    {
        if ((*it)->name_ == name)
        {
            pods_.erase(it);
            return true;
        }
    }
    return false;
}

bool KubernetesCluster::schedulePod(Pod &pod)
{
    double sum_cpu = 0, sum_memory = 0;
    for (auto it = pod.containers_.begin(); it != pod.containers_.end(); ++it)
    {
        sum_cpu += (*it)->cpu_;
        sum_memory += (*it)->cpu_;
    }
    for (auto i = nodes_.begin(); i != nodes_.end(); ++i)
    {
        if ((*i)->available_cpu_ >= sum_cpu && (*i)->available_memory >= sum_memory)
            return true;
    }
    return false;
}

void KubernetesCluster::deployPod(std::unique_ptr<Pod> pod)
{
    try
    {
        if (this->schedulePod(*pod))
        {
            double sum_cpu = 0, sum_memory = 0;
            for (const auto &container : pod->containers_)
            {
                sum_cpu += container->cpu_;
                sum_memory += container->memory_;
            }
            for (const auto &node : nodes_)
            {
                if (node->allocate(sum_cpu, sum_memory))
                {
                    pods_.push_back(std::move(pod));
                    return;
                }
            }
        }
    } catch (AllocationException e)
    {
        cerr << e.what() << endl;
    }
}

Pod *KubernetesCluster::getPod(const std::string &name)
{
    for (auto &x : pods_)
    {
        if (x->name_ == name)
        {
            return &(*x);
        }
    }
    return nullptr;
}

std::string KubernetesCluster::getMetrics() const
{
    string res = "Les serveurs : \n";
    for (auto &x : nodes_)
    {
        res += x->getMetrics() + "\n";
    }
    res += "\nLes pods : \n";
    for (auto &x : pods_)
    {
        res += x->getMetrics() + "\n";
    }
    return res;
}

std::ostream &operator<<(std::ostream &os, const KubernetesCluster &c)
{
    os << c.getMetrics();
    return os;
}

const vector<unique_ptr<Pod>>& KubernetesCluster::getPods() const {
    return pods_;
}


std::vector<std::shared_ptr<Server>> KubernetesCluster::getFilteredServers(const std::function<bool(const Server&)>& predicate) const {
    std::vector<std::shared_ptr<Server>> result;
    for (const auto& server : nodes_) {
        if (predicate(*server)) {
            result.push_back(server);
        }
    }
    return result;
}
