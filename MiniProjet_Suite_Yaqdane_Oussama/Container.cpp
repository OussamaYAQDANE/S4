#include "Container.hpp"
#include <iomanip>

using namespace std;

Container::Container(string id, string image, double cpu, double memory)
    : Resource(id, cpu, memory), image_(image)
{}

std::string Container::getMetrics() const {
    std::ostringstream oss;
    oss << "[Container: " << std::left << std::setw(15) << id_ << " : " <<
           std::setw(15) << std::to_string(cpu_) << " , " <<
           std::setw(15) << std::to_string(memory_) << " , " <<
           std::setw(15) << image_ << " ].";
    return oss.str();
}

ostream& operator<<(ostream& os, Container container){
    os << "[Container: " + container.id_ + " : "  + to_string(container.cpu_) + ", " + to_string(container.memory_) + ", " + container.image_ + "]";
    return os;
}

void Container::start() {active_ = true;}
void Container::stop() {active_ = false;}