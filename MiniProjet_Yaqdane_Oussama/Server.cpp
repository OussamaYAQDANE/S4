#include "Server.h"


Server::Server(std::string id, double cpu, double memory) 
: Resource(id, cpu, memory), available_cpu_(cpu), available_memory_(memory) {}


bool Server::allocate(double cpu, double memory){
    if (available_cpu_>= cpu && available_memory_>=memory){
        available_cpu_ -= cpu;
        available_memory_ -= memory;
        return true;
    }
    return false;
}

void Server::start() {active_ = true;}
void Server::stop() {active_ = false;}

std::string Server::getMetrics() const{
    return "[Server: " + id_ + " : " +
    std::to_string(cpu_) + " , " +
    std::to_string(memory_) + " , " +
    std::to_string(available_cpu_) + " , " +
    std::to_string(available_memory_) + " , " +
    " ].";
}

std::ostream& operator<<(std::ostream& os, const Server& s){
    os << s.getMetrics();
    return os;
}

double Server::getAvailableCpu(){
    return available_cpu_;
}
double Server::getAvailableMemory(){
    return available_memory_;
}
Server::~Server() {}