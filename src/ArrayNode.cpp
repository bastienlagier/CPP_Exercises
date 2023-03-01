#include "ArrayNode.hpp"
#include <utility>
#include <algorithm>

std::string ArrayNode::print() const {
    std::string result = "[";
    for (unsigned i = 0; i < _array.size(); ++i) {
        if (i > 0)
            result += ",";
        result += _array[i]->print();
    }
    result += ']';
    return result;
}

std::unique_ptr<ArrayNode> ArrayNode::make_ptr() {
    return std::make_unique<ArrayNode>(ArrayNode { });
}

int ArrayNode::child_count() {
    return _array.size();
}

void ArrayNode::push_back(NodePtr nodeptr) {
    _array.push_back(std::move(nodeptr));
}

unsigned int ArrayNode::node_count() {
    unsigned int count = 1;
    for (const auto &node : _array) {
        count += node->node_count();
    }
    return count;
}

unsigned int ArrayNode::height() {
    if (child_count() == 0u) {
        return 0u;
    }
    unsigned int height = 0;
    for (const auto &node : _array) {
        height = std::max(node->height(), height);
    }
    return height + 1;
}