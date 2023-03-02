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
    virtual size_t child_count() const = 0;
    virtual unsigned int height() { return 0u; };
    virtual unsigned int node_count();
    virtual bool operator==(const Node&) const = 0;
    virtual NodePtr deep_copy() const = 0;
    NodeKind kind() const { return _kind; };
    IntLeaf* as_IntLeaf();
    StringLeaf* as_StringLeaf(); 
    ArrayNode* as_ArrayNode();
    ObjectNode* as_ObjectNode();
    const IntLeaf* as_IntLeaf() const;
    const StringLeaf* as_StringLeaf() const; 
    const ArrayNode* as_ArrayNode() const;
    const ObjectNode* as_ObjectNode() const;
};