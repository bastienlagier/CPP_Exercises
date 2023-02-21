#include "ArrayNode.hpp"


NodeKind ArrayNode::kind() const {
    return _kind;
}

std::string ArrayNode::print() const {
    return "[]";
}