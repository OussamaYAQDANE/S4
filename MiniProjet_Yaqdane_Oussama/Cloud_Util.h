#include "KubernetesCluster.h"

void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods);

void display(const KubernetesCluster& cluster);
