#include "IntLeaf.hpp"

bool IntLeaf::operator==(const Node& other) const
{
    if (other.kind() != kind())
    {
        return false;
    }
    return (_value == other.as_IntLeaf()->_value);
}

std::string IntLeaf::print() const {
    return std::to_string(_value);
}

int IntLeaf::data() const {
    return _value;
}

std::unique_ptr<IntLeaf> IntLeaf::make_ptr(int value) {
    return std::make_unique<IntLeaf>(value);
}

size_t IntLeaf::child_count() const {
    return 0;
}