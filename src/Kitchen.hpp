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
#include "../lib/Cupboard.hpp"

class Kitchen
{
    public:
    const Unit& register_unit(Unit unit);
    const Unit* find_unit(const std::string& name) const;


    const Ingredient& register_ingredient(Ingredient ingredient);
    const Ingredient* find_ingredient(const std::string& name) const;

    const std::optional<Consumable> make_random_consumable(float quantity, unsigned int expiration) const;

    const Cupboard& get_cupboard() const;
    void store_in_cupboard(Consumable consumable);
    void wait_time(unsigned int time);
    float compute_quantity(const std::function<bool(const Consumable&)>& consumable_filter) const;
    float compute_quantity(const Ingredient& ingredient) const;

    private:
    std::vector<std::reference_wrapper<Unit>> _units;
    std::vector<std::reference_wrapper<Ingredient>> _ingredients;
    std::unique_ptr<Cupboard> _cupboard;
};
