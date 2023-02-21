#include "ArrayNode.hpp"

NodeKind ArrayNode::kind() const {
    return _kind;
}

std::string ArrayNode::print() const {
    return "[]";
}

NodePtr ArrayNode::make_ptr() {
    return std::make_unique<ArrayNode>(ArrayNode { });
}

int ArrayNode::child_count() {
    return 0;
}