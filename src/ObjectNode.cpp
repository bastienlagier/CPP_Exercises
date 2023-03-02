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
    auto result = std::make_unique<ObjectNode>();
    std::map<std::string, NodePtr> _dictionnary = {};
    result->_dictionnary = std::move(_dictionnary);
    return result;
}

unsigned int ObjectNode::node_count() {
    unsigned int count = 1;
    for (const auto& entry : _dictionnary) {
        count += entry.second->node_count();
    }
    return count;
}

void ObjectNode::insert(std::string str, NodePtr nodeptr) {
    if (nodeptr != nullptr) {
        unsigned int nodecount = nodeptr->node_count();
        _dictionnary.insert_or_assign(str, std::move(nodeptr));
    }
}

unsigned int ObjectNode::height() {
    if (child_count() == 0) {
        return 0u;
    }
    unsigned int height = 0;
    for (auto it = _dictionnary.begin(); it != _dictionnary.end(); ++it) {
        height = std::max(it->second->height(), height);
    }
    return height+1;
}

bool ObjectNode::has_child(const std::string& key) const {
    return _dictionnary.count(key) != 0;
}

Node* ObjectNode::at(const std::string& key) {
    if (has_child(key))
        return _dictionnary.at(key).get();
    else
        return nullptr;
}

const Node* ObjectNode::at(const std::string& key) const {
    if (has_child(key))
        return _dictionnary.at(key).get();
    else
        return nullptr;
}

bool ObjectNode::operator==(const Node& other) const
{
    if (other.kind() != kind())
        return false;

    ObjectNode const* other_s = other.as_ObjectNode();
    if (other_s->child_count() != this->child_count())
        return false;
    for (auto& pair : other_s->_dictionnary)
    {
        auto it = _dictionnary.find(pair.first);
        if (it == _dictionnary.end())
            return false;
        if (!(*(it->second) == *(pair.second)))
            return false;
    }
    return true;
}

NodePtr ObjectNode::deep_copy() const
{
    auto result = make_ptr();
    for (auto const& [key, child] : _dictionnary)
        result->insert(key, child->deep_copy());
    return result;
}