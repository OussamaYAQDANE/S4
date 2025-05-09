#include "Pod.hpp"
#include <iomanip>

Pod::Pod(string name, unordered_map<string, string> labels): labels_(labels), name_(name){}

void Pod::addContainer(unique_ptr<Container> container){
    containers_.push_back(move(container));
}

bool Pod::removeContainer(const string& id){
    for (auto it = containers_.begin(); it != containers_.end(); it++){
       if((*it)->id_ == id){
        containers_.erase(it);
        return true;
       }
    }
    return false;
}

void Pod::deploy(){
    for (auto it = containers_.begin(); it != containers_.end(); it++){
        (*it)->start();
    }
}

std::string Pod::getMetrics() const{
    std::ostringstream res;
    for (auto& x : containers_){
        res << std::left << std::setw(15) << x->getMetrics() << " ";
    }
    res << '\n';
    return res.str();
}
std::ostream& operator<<(std::ostream& os, const Pod& p){
    os << p.getMetrics();
    return os;
}

const vector<unique_ptr<Container>>& Pod::getContainers() const{
    return containers_;
}
