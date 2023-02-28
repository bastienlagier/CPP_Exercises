#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"
#include <array>
#include <vector>

class ArrayNode : public Node {
    public:
    ArrayNode() 
        : Node {}
        , _kind { NodeKind::ARRAY }
    {}
    NodeKind kind() const;
    virtual std::string print() const override;
    static std::unique_ptr<ArrayNode> make_ptr();
    void push_back(NodePtr nodeptr);
    int child_count() override;
    unsigned int node_count() override { return _array.size()+1; };
    unsigned int height() override;
    private:
    std::vector<NodePtr> _array;
    const NodeKind _kind;
};