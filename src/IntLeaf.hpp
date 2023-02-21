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
    static NodePtr make_ptr(int value);
    int child_count();
    private:
    const int _value;      
    const NodeKind _kind;
};