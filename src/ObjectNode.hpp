#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"


class ObjectNode : public Node {
    public:
    ObjectNode() 
        : Node {}
        , _kind { NodeKind::OBJECT }
    {}
    NodeKind kind() const;
    virtual std::string print() const override;
    static NodePtr make_ptr();
    int child_count();
    private:
    const NodeKind _kind;
};