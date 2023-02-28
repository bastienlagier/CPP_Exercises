#pragma once
#include "Leaf.hpp"
#include <string>

class IntLeaf : public Leaf {
    public:
    IntLeaf(const int value) 
        : Leaf { NodeKind::INT }
        , _value { value }
    {}
    int data() const;
    virtual std::string print() const override;
    static NodePtr make_ptr(int value);
    int child_count();
    private:
    const int _value;
};