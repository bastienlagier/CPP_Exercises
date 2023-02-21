#include "Leaf.hpp"
#include "NodeKind.hpp"
#include <string>

class StringLeaf : public Leaf {
    public:
    StringLeaf(const std::string& value) 
        : Leaf {}
        , _value { value }
        , _kind { NodeKind::STRING }
    {}
    std::string data() const;
    NodeKind kind() const;
    virtual std::string print() const override;
    private:
    const std::string _value;      
    const NodeKind _kind;
};