#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"
#include <string>

class IntLeaf : public Leaf {
    public:
    IntLeaf(const int value) 
        : Leaf {}
        , _value { value }
        , _kind { NodeKind::INT }
    {}
    int data() const;
    NodeKind kind() const;
    virtual std::string print() const override;
    private:
    const int _value;      
    const NodeKind _kind;
};