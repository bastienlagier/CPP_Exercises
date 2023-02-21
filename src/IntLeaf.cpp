#include "IntLeaf.hpp"


NodeKind IntLeaf::kind() const {
    return _kind;
}

std::string IntLeaf::print() const {
    return std::to_string(_value);
}

int IntLeaf::data() const {
    return _value;
}

NodePtr IntLeaf::make_ptr(int value) {
    return std::make_unique<IntLeaf>(IntLeaf { value });
}

int IntLeaf::child_count() {
    return 0;
}