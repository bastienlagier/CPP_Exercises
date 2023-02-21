#pragma once
#include "InstanceCounter.hpp"
#include <string>

class Node : public InstanceCounter {
    protected:
    Node()
    {}
    public:
    virtual ~Node() {}
    virtual std::string print() const = 0;
};