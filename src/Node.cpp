#include "Node.hpp"
#include "IntLeaf.hpp"
#include "StringLeaf.hpp"

unsigned int Node::node_count() {
    return 1u;
}

IntLeaf* Node::as_IntLeaf() {
    return dynamic_cast<IntLeaf*>(this);
}

StringLeaf* Node::as_StringLeaf() {
    return dynamic_cast<StringLeaf*>(this);
}