#ifndef CLUSTER
#define CLUSTER

#include <memory>
#include <vector>
#include "Server.h"
#include "Pod.h"

class KubernetesCluster
{
private:
    vector<std::shared_ptr<Server>> nodes_;
    vector<std::unique_ptr<Pod>> pods_;
public:

    // KubernetesCluster(const KubernetesCluster&) = delete;
    // KubernetesCluster& operator=(const KubernetesCluster&) = delete;

    KubernetesCluster();
    void addNode(std::shared_ptr<Server> node);
    bool removePod(const std::string& name);
    void deployPod(std::unique_ptr<Pod> pod);
    bool schedulePod(Pod& pod);
    Pod* getPod(const std::string& name);
    std::string getMetrics() const;
    friend std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c);
    
    ~KubernetesCluster();
};

#endif


