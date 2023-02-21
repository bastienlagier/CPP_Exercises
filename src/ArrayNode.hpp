#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"
#include <array>

class ArrayNode : public Node {
    public:
    ArrayNode() 
        : Node {}
        , _kind { NodeKind::ARRAY }
    {}
    NodeKind kind() const;
    virtual std::string print() const override;
    private:
    const NodeKind _kind;
};