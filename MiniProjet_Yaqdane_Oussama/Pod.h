#ifndef POD
#define POD

#include "Container.h"
#include <vector>
#include <memory>
#include <unordered_map>

class Pod
{
private:
    string name_;
    vector<std::unique_ptr<Container>> containers_ = {};
    std::unordered_map<std::string, std::string> labels_;
public:
    Pod(std::string name, std::unordered_map<std::string, std::string> labels = {});
    void addContainer(std::unique_ptr<Container> container);
    bool removeContainer(const std::string& id);
    std::string getMetrics() const;
    friend std::ostream& operator<<(std::ostream& os, const Pod& p);
    const std::vector<std::unique_ptr<Container>>& getContainers() const;
    void deploy();
    double getCPU();
    double getMEMORY();
    string getName();
    ~Pod();
};

#endif