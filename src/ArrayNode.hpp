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
    static NodePtr make_ptr();
    int child_count() override;
    private:
    std::vector<Node> _array;
    const NodeKind _kind;
};