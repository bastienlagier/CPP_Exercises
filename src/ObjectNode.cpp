#include "ObjectNode.hpp"

NodeKind ObjectNode::kind() const {
    return _kind;
}

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
    _dictionnary.insert_or_assign(str, std::move(nodeptr));
}