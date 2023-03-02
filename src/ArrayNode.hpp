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
    NodeKind kind() const;
    virtual std::string print() const override;
    static std::unique_ptr<ArrayNode> make_ptr();
    void push_back(NodePtr nodeptr);
    int child_count() override;
    unsigned int node_count() override;
    unsigned int height() override;
    std::vector<NodePtr>::const_iterator begin() const { return _array.begin(); }
    std::vector<NodePtr>::const_iterator end() const { return _array.end(); }
    private:
    std::vector<NodePtr> _array;
};