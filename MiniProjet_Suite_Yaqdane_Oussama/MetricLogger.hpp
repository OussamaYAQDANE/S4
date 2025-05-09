#pragma once
#include <iostream>
#include <string>
#include "KubernetesCluster.hpp"

template <typename T>
class MetricLogger{
    public:
        static void logToStream(const T& obj, std::ostream& out, const std::string& label){
            out << label << ": "<< obj.getMetrics() << std::endl;
        }
};
