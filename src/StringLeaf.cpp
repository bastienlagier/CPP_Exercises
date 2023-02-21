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