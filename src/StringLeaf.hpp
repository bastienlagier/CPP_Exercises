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
    virtual std::string print() const override;
    static std::unique_ptr<StringLeaf> make_ptr(const std::string& value);
    bool operator==(const Node& other) const override;
    size_t child_count() const override;
    NodePtr deep_copy() const override { return make_ptr(data()); }
    private:
    const std::string _value;
};