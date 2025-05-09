#include "Cloud_Util.hpp"
#include <fstream>
#include "CloudExceptions.hpp"
#include "functional"
void deployPods(KubernetesCluster &cluster, std::vector<std::unique_ptr<Pod>> &pods)
{
    for (auto &x : pods)
    {
        try
        {
            cluster.deployPod(std::move(x));
        }
        catch (AllocationException e)
        {
            cerr << e.what() << endl;
        }
    }
}

void display(const KubernetesCluster &cluster)
{
    cout << "displaying infos" << endl;
    cout << cluster << endl;
}

void saveClusterMetrics(const KubernetesCluster &cluster, const std::string &filename)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        throw FileException("Couldn't open file");
    }
    file << cluster.getMetrics();
    file.close();
}


void forEachContainer(const KubernetesCluster& cluster, const std::function<void(const Container&)>& func) {
    for (const auto& pod : cluster.getPods()) {
        for (const auto& container : pod->getContainers()) {
            func(*container);
        }
    }
}
