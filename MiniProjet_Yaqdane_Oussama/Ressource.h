#ifndef RESSOURCE
#define RESSOURCE

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
    Resource(std::string id, double cpu, double memory);
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual std::string getMetrics() const = 0;
    virtual ~Resource() = default;
};

#endif

