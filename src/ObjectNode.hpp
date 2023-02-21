#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"
#include <array>


class ObjectNode : public Node {
    public:
    ObjectNode() 
        : Node {}
        , _kind { NodeKind::OBJECT }
    {}
    NodeKind kind() const;
    virtual std::string print() const override;
    private:
    const NodeKind _kind;
};