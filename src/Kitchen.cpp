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

const std::optional<Consumable> Kitchen::make_random_consumable(float quantity, unsigned int expiration) const {
    if (_ingredients.empty()) {
        return std::nullopt;
    }
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<size_t> uniform_dist(0u, _ingredients.size()-1u);
    int id = uniform_dist(e1);
    auto ingredient = _ingredients.at(id);
    Consumable consumable{ ingredient, quantity, expiration };
    return consumable;
}

const Cupboard& Kitchen::get_cupboard() const {
    return (*_cupboard);
}

void Kitchen::store_in_cupboard(Consumable consumable) {
    (*_cupboard).consumables.push_back(consumable);
}

void Kitchen::wait_time(unsigned int time) {
    auto& consumables = (*_cupboard).consumables;
    std::for_each(consumables.begin(), consumables.end(), 
        [time](Consumable consumable) { 
            if (!consumable.expiration_time.has_value()) {
                return;
            }
            std::optional<unsigned int> expiration = 
                consumable.expiration_time.value() - time;
            consumable.expiration_time = expiration; });
}

float Kitchen::compute_quantity(const std::function<bool(const Consumable&)>& consumable_filter) const {
    auto& consumables = (*_cupboard).consumables;
    return std::accumulate(consumables.begin(), consumables.end(), 0.f,
        [&consumable_filter](float r, const Consumable& c) {
            const auto quantity = consumable_filter(c) ? c.quantity : 0.f;
            return r + quantity;
        });
}


float Kitchen::compute_quantity(const Ingredient& ingredient) const {
    return compute_quantity([&ingredient](const Consumable& c)
        { return c.expiration_time != 0 && &c.ingredient.get() == &ingredient; });
}