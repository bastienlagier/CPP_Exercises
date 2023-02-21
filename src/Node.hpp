#pragma once
#include "InstanceCounter.hpp"
#include <string>
#include <memory>

class Node;

using NodePtr = std::unique_ptr<Node>;

class Node : public InstanceCounter {
    protected:
    Node()
    {}
    public:
    virtual ~Node() {}
    virtual std::string print() const = 0;
    virtual int child_count() = 0;
};