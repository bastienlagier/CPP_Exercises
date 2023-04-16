#include "Kitchen.hpp"


const Unit& Kitchen::register_unit(Unit unit) {
    return _units.emplace_back(unit);
}

const Unit* Kitchen::find_unit(const std::string& name) const {
    const auto it = std::find_if(_units.begin(), _units.end(), [name](Unit unit) { return unit.name == name ; });
    return it == _units.end() ? nullptr : &((*it).get());
}

const Ingredient& Kitchen::register_ingredient(Ingredient ingredient) {
    return _ingredients.emplace_back(ingredient);
}

std::string to_upper(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), 
                   [](unsigned char c){ return std::toupper(c); }
    );
    return s;
}

const Ingredient* Kitchen::find_ingredient(const std::string& name) const {
    const auto it = std::find_if(_ingredients.begin(), _ingredients.end(), 
        [name](Ingredient i) { return to_upper(i.name) == to_upper(name); });
    return it == _ingredients.end() ? nullptr : &((*it).get());
}