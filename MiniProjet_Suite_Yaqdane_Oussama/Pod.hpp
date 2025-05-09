#pragma once

#include <memory>
#include "Container.hpp"
#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Pod
{
private:
    string name_;
    vector<unique_ptr<Container>> containers_;
    unordered_map<string, string> labels_;
public:
    Pod(string name, unordered_map<string, string> labels);
    
    void addContainer(unique_ptr<Container> container);
    bool removeContainer(const string& id);
    void deploy();
    string getMetrics() const;
    friend std::ostream& operator<<(std::ostream& os, const Pod& p);
    friend class KubernetesCluster;
    const vector<unique_ptr<Container>>& getContainers() const;
};

