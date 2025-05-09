#include "KubernetesCluster.hpp"

void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods);

void display(const KubernetesCluster& cluster);

void saveClusterMetrics(const KubernetesCluster& cluster, const std::string& filename);

void forEachContainer(const KubernetesCluster& cluster, const std::function<void(const Container&)>& func);
