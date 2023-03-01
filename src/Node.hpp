#pragma once
#include "InstanceCounter.hpp"
#include <string>
#include <memory>
#include "NodeKind.hpp"

class Node;
class ArrayNode;
class IntLeaf;
class StringLeaf;
class ArrayNode;
class ObjectNode;

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
    IntLeaf* as_IntLeaf();
    StringLeaf* as_StringLeaf(); 
    ArrayNode* as_ArrayNode();
    ObjectNode* as_ObjectNode();
};