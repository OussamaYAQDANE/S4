#pragma once

#include <string>
#include "Resource.hpp"
#include <iostream>
using namespace std;
class Container: public Resource
{
private:
    string image_;
public:
    Container(string id, string image, double cpu, double memory);
    
    void start() override;
    void stop() override;
    string getMetrics() const override;

    friend ostream& operator<<(ostream& os, Container container);
    friend class Pod;
    friend class KubernetesCluster;

};


