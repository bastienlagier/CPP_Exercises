#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"
#include <map>
#include <string>

class ObjectNode : public Node {
    public:
    ObjectNode() 
        : Node {}
        , _kind { NodeKind::OBJECT }
    {}
    NodeKind kind() const;
    virtual std::string print() const override;
    static std::unique_ptr<ObjectNode> make_ptr();
    int child_count();
    void insert(std::string str, NodePtr nodeptr);
    private:
    const NodeKind _kind;
    std::map<std::string, NodePtr> _dictionnary;
};