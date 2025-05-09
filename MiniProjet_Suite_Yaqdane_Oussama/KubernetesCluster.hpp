#pragma once

#include <memory>
#include <string>
#include <iostream>
#include "Pod.hpp"
#include "Server.hpp"
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class KubernetesCluster
{
private:
    vector<shared_ptr<Server>> nodes_;
    vector<unique_ptr<Pod>> pods_;
public:
    void addNode(shared_ptr<Server> server);
    bool removePod(const string& name);
    void deployPod(std::unique_ptr<Pod> pod);
    bool schedulePod(Pod& pod);
    Pod* getPod(const std::string& name);
    std::string getMetrics() const;
    friend std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c);
    std::vector<std::shared_ptr<Server>> getFilteredServers(const std::function<bool(const Server&)>& predicate) const;
    const vector<unique_ptr<Pod>>& getPods() const;
};









