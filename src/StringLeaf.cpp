#include "StringLeaf.hpp"

std::string StringLeaf::print() const {
    return "\"" +  _value + "\"";
}

std::string StringLeaf::data() const {
    return _value;
}

std::unique_ptr<StringLeaf> StringLeaf::make_ptr(const std::string& value) {
    return std::make_unique<StringLeaf>(std::move(value));
}

bool StringLeaf::operator==(const Node& other) const
{
    if (other.kind() != kind())
    {
        return false;
    }
    return (_value == other.as_StringLeaf()->_value);
}

size_t StringLeaf::child_count() const {
    return 0;
}