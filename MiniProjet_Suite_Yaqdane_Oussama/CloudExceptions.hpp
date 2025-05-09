#pragma once

#include <exception>
#include <string>
#include <stdexcept>
using namespace std;

class CloudException : public std::runtime_error
{
};

class AllocationException : public std::exception
{
    string message;
public:

    AllocationException(string message): message(message){}

    const char* what() const noexcept override{
        return message.c_str();
    }
};

class FileException : public std::exception
{
    string message;
public:

    FileException(string message): message(message){}

    const char* what() const noexcept override{
        return message.c_str();
    }
};