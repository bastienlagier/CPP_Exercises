#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"
#include <array>
#include <vector>

class ArrayNode : public Node {
    public:
    ArrayNode() 
        : Node { NodeKind::ARRAY }
    {}
    virtual std::string print() const override;
    static std::unique_ptr<ArrayNode> make_ptr();
    void push_back(NodePtr nodeptr);
    size_t child_count() const override;
    unsigned int node_count() override;
    unsigned int height() override;
    std::vector<NodePtr>::iterator begin() { return _array.begin(); }
    std::vector<NodePtr>::iterator end() { return _array.end(); }

    std::vector<NodePtr>::const_iterator begin() const { return _array.begin(); }
    std::vector<NodePtr>::const_iterator end() const { return _array.end(); }

    NodePtr deep_copy() const;

    bool operator==(const Node& other) const;
    private:
    std::vector<NodePtr> _array;
};