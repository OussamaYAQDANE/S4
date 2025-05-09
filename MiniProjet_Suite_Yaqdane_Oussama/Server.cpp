#include "Server.hpp"
#include "CloudExceptions.hpp"
#include "iomanip"

Server::Server(string id, double cpu, double memory): Resource(id, cpu, memory), available_cpu_(cpu), available_memory(memory){}

void Server::start() {active_ = true;}
void Server::stop() {active_ = false;}
bool Server::isActive() const {return active_;}

bool Server::allocate(double cpu, double memory){
    if (!active_){
        throw AllocationException("Inactive server.");
    }
    if (available_cpu_ >= cpu && available_memory > memory){
        available_cpu_ -= cpu;
        available_memory -= memory;
        return true;
    }
    throw AllocationException("Available resources aren't enough.");
    return false;
}
std::string Server::getMetrics() const{
    std::ostringstream oss;
    oss << "[Server: " << std::left << std::setw(10) << id_ << " : " <<
    std::setw(10) << std::to_string(cpu_) << " , " <<
    std::setw(10) << std::to_string(memory_) << " , " <<
    std::setw(10) << std::to_string(available_cpu_) << " , " <<
    std::setw(10) << std::to_string(available_memory) <<
    " ].";
    return oss.str();
}

ostream& operator<<(ostream& os, const Server& server){
    os << server.getMetrics();
    return os;
}