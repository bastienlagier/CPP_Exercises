#include "ObjectNode.hpp"

std::string ObjectNode::print() const {
    std::string res = "{";
    bool first = true;
    for (auto it = _dictionnary.begin(); it != _dictionnary.end(); ++it) {
        if (first) {
            first = false;
        }
        else {
            res += ",";
        }
        res += "\"" + it->first  +  "\":" + it->second->print();
    }
    return res + "}";
}

std::unique_ptr<ObjectNode> ObjectNode::make_ptr() {
    return std::make_unique<ObjectNode>(ObjectNode { });
}

int ObjectNode::child_count() {
    return _dictionnary.size();
}

void ObjectNode::insert(std::string str, NodePtr nodeptr) {
    if (nodeptr != nullptr) {
        unsigned int nodecount = nodeptr->node_count();
        _dictionnary.insert_or_assign(str, std::move(nodeptr));
        _node_count += nodecount;
    }
}

unsigned int ObjectNode::height() {
    unsigned int size = _dictionnary.size();
    return size == 0 ? 0 : size-1;
}