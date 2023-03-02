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
    static std::unique_ptr<IntLeaf> make_ptr(int value);
    bool operator==(const Node& other) const;
    size_t child_count() const override;
    NodePtr deep_copy() const override { return make_ptr(data()); }
    private:
    const int _value;
};