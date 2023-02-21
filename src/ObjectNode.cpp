#include "ObjectNode.hpp"

NodeKind ObjectNode::kind() const {
    return _kind;
}

std::string ObjectNode::print() const {
    return "{}";
}