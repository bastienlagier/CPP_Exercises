#pragma once
#include "Node.hpp"
#include <map>
#include <string>

class ObjectNode : public Node {
    public:
    ObjectNode() 
        : Node { NodeKind::OBJECT }
    {}
    virtual std::string print() const override;
    static std::unique_ptr<ObjectNode> make_ptr();
    size_t child_count() const { return _dictionnary.size(); }
    void insert(std::string str, NodePtr nodeptr);
    unsigned int node_count() override;
    unsigned int height() override;
    bool has_child(const std::string& key) const;
    Node* at(const std::string& key);
    const Node* at(const std::string& key) const;
    bool operator==(const Node& other) const override;
    NodePtr deep_copy() const;
    private:
    std::map<std::string, NodePtr> _dictionnary;
};