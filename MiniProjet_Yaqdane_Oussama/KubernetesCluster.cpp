#include "KubernetesCluster.h"


void KubernetesCluster::addNode(std::shared_ptr<Server> node){
    nodes_.push_back(node);
}

bool KubernetesCluster::removePod(const std::string& name){
    for (auto x = pods_.begin(); x<pods_.end(); ++x){
        if ((*x)->getName() == name){
            pods_.erase(x);
            return true;
        }
    }
    return false;
}

bool KubernetesCluster::schedulePod(Pod& pod){
    for (auto& x : nodes_){
        if (x->getAvailableCpu() >= pod.getCPU() && x->getAvailableMemory()>= pod.getMEMORY()){
            return true;
        }
    }
    return false;
}


void KubernetesCluster::deployPod(std::unique_ptr<Pod> pod){
    if (this->schedulePod(*pod)){
        for (auto& x : nodes_){
            if (x->getAvailableCpu() >= (*pod).getCPU() && x->getAvailableMemory() >= (*pod).getMEMORY()){
                x->allocate((*pod).getCPU(), (*pod).getMEMORY());
                pod->deploy();
                pods_.push_back(std::move(pod));
                return;
            }
        }
    }
}


Pod* KubernetesCluster::getPod(const std::string& name){
    for (auto& x : pods_){
        if (x->getName() == name){
            return x.get();
        }
    }
    return nullptr;
}




std::string KubernetesCluster::getMetrics() const{
    string res = "Les serveurs : \n";
    for (auto& x : nodes_){
        res += x->getMetrics() + "\n";
    }
    res += "\nLes pods : \n";
    for (auto& x : pods_){
        res += x->getMetrics() + "\n";
    }
    return res;
}

std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c){
    os << c.getMetrics();
    return os;
}




KubernetesCluster::KubernetesCluster(/* args */) {}

KubernetesCluster::~KubernetesCluster() {}