#pragma once
#include "Node.hpp"
#include <map>
#include <string>

class ObjectNode : public Node {
    public:
    ObjectNode() 
        : Node { NodeKind::OBJECT }
    {}
    NodeKind kind() const;
    virtual std::string print() const override;
    static std::unique_ptr<ObjectNode> make_ptr();
    int child_count();
    void insert(std::string str, NodePtr nodeptr);
    unsigned int node_count() override;
    unsigned int height() override;
    bool has_child(const std::string& key);
    Node* at(const std::string& key);
    private:
    std::map<std::string, NodePtr> _dictionnary;
};