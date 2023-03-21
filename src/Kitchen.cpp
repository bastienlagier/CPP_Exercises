#include "Kitchen.hpp"

const Unit& Kitchen::register_unit(Unit unit) {
    return _array.emplace_back(unit);
}

const Unit* Kitchen::find_unit(const std::string& name) const {
    auto lambda = [name](const Unit& u) { return u.name == name; };
    auto unit = std::find_if(std::begin(_array), std::end(_array), lambda); 
    if (unit != std::end(_array)) {
        return &(*unit);
    }
    return nullptr;
}