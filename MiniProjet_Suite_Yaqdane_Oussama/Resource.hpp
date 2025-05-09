#pragma once

#include <string>

using namespace std;


class Resource
{
protected:
    string id_;
    double cpu_;
    double memory_;
    bool active_;

public:
    Resource(string id, double cpu, double memory);

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual string getMetrics() const = 0;

    virtual ~Resource() = default;
};