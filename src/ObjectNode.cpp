#include "ObjectNode.hpp"

NodeKind ObjectNode::kind() const {
    return _kind;
}

std::string ObjectNode::print() const {
    return "{}";
}

NodePtr ObjectNode::make_ptr() {
    return std::make_unique<ObjectNode>(ObjectNode { });
}

int ObjectNode::child_count() {
    return 0;
}