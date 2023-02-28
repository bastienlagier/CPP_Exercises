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

unsigned int ArrayNode::height() {
    // unsigned int size = _array.size();
    // return size == 0 ? 0 : size-1;
    unsigned int height = 1;
    for (const auto &node : _array) {
        height = std::max(node->height(), height);
    }
    return height;
}