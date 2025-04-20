#include "Cloud_Util.h"

void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods){
    for (auto& x : pods){
        cluster.deployPod(std::move(x));
    }
}

void display(const KubernetesCluster& cluster) {
   cout << "displaying infos" << endl;
   cout << cluster << endl;
}