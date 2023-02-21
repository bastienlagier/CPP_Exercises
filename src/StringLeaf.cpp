#include "StringLeaf.hpp"


NodeKind StringLeaf::kind() const {
    return _kind;
}

std::string StringLeaf::print() const {
    return "\"" +  _value + "\"";
}

std::string StringLeaf::data() const {
    return _value;
}

NodePtr StringLeaf::make_ptr(const std::string& value) {
    return std::make_unique<StringLeaf>(StringLeaf { value } );
}

int StringLeaf::child_count() {
    return 0;
}