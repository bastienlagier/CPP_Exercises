#pragma once
#include "Node.hpp"

class Leaf : public Node {
    protected:
    Leaf(NodeKind kind)
        : Node(kind)
    {}
};