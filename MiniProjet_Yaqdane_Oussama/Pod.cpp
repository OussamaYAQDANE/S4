#include "Pod.h"

Pod::Pod(std::string name, std::unordered_map<std::string, std::string> labels) : name_(name), labels_(labels) {}

void Pod::addContainer(std::unique_ptr<Container> container){
    containers_.push_back(std::move(container));
}

bool Pod::removeContainer(const std::string& id){
    for (auto x = containers_.begin(); x<containers_.end(); ++x){
        if ((*x)->getId() == id){
            containers_.erase(x);
            return true;
        }
    }
    return false;
}

std::string Pod::getMetrics() const{
    string res = "";
    for (auto& x : containers_){
        res += x->getMetrics() + " ";
    }
    res += '\n';
    return res;
}

std::ostream& operator<<(std::ostream& os, const Pod& p){
    os << p.getMetrics();
    return os;
}

void Pod::deploy(){
    for (auto& x : containers_){
        x->start();
    }
}

const std::vector<std::unique_ptr<Container>>& Pod::getContainers() const{
    return containers_;
}

string Pod::getName(){
    return name_;
}

double Pod::getCPU(){
    double res = 0;
    for (auto& x : containers_){
        res += x->getCPU();
    }
    return res;
}
double Pod::getMEMORY(){
    double res = 0;
    for (auto& x : containers_){
        res += x->getMEMORY();
    }
    return res;
}

Pod::~Pod() {}