#pragma once
#include "InstanceCounter.hpp"
#include <string>
#include <memory>
#include "NodeKind.hpp"

class Node;
class ArrayNode;

using NodePtr = std::unique_ptr<Node>;

class Node : public InstanceCounter {
    private:
    const NodeKind _kind;
    protected:
    Node(NodeKind kind)
        : _kind(kind)
    {}
    public:
    virtual ~Node() = default;
    virtual std::string print() const = 0;
    virtual int child_count() = 0;
    virtual unsigned int height() { return 0u; };
    virtual unsigned int node_count();
    virtual NodeKind kind() { return _kind; };
};