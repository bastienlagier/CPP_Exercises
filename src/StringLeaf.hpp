#include "Leaf.hpp"
#include "NodeKind.hpp"
#include <string>

class StringLeaf : public Leaf {
    public:
    StringLeaf(const std::string& value) 
        : Leaf { NodeKind::STRING }
        , _value { value }
    {}
    std::string data() const;
    NodeKind kind() const;
    virtual std::string print() const override;
    static NodePtr make_ptr(const std::string& value);
    int child_count();
    private:
    const std::string _value;
};