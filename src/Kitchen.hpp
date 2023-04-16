#pragma once

#include <vector>
#include <list>
#include <iostream>
#include <memory>
#include <algorithm>
#include <optional>
#include <set>
#include <random>

#include "../lib/Unit.hpp"
#include "../lib/Ingredient.hpp"
#include "../lib/Consumable.hpp"

class Kitchen
{
    public:
    const Unit& register_unit(Unit unit);
    const Unit* find_unit(const std::string& name) const;


    const Ingredient& register_ingredient(Ingredient ingredient);
    const Ingredient* find_ingredient(const std::string& name) const;

    const std::optional<Consumable> make_random_consumable(float quantity, unsigned int expiration) const;

    private:
    std::vector<std::reference_wrapper<Unit>> _units;
    std::vector<std::reference_wrapper<Ingredient>> _ingredients;
};
