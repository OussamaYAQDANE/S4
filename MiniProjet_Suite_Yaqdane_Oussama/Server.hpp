#pragma once

#include "Resource.hpp"
#include <string>
#include <iostream>

using namespace std;
class Server: public Resource
{
private:
    double available_cpu_;
    double available_memory;
public:
    Server(string id, double cpu, double memory);
    bool allocate(double cpu, double memory);
    bool isActive() const ;
    void start() override;
    void stop() override;
    std::string getMetrics() const override;
    friend std::ostream& operator<<(std::ostream& os, const Server& server);
    friend class KubernetesCluster;
};




