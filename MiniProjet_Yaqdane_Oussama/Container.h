#ifndef CONTAIN
#define CONTAIN

#include "Ressource.h"
#include <iostream>

class Container : public Resource
{
private:
    string image_;
public:
    Container(std::string id, std::string image, double cpu, double memory);
    void start() override;
    void stop() override;
    std::string getMetrics() const override;
    friend std::ostream& operator<<(ostream& os,const Container& C);
    ~Container();
    string getId() const;
    double getCPU();
    double getMEMORY();
};

#endif


