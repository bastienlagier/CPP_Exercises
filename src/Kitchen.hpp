#pragma once
#include "../lib/Unit.hpp"
#include <vector>
#include <memory>
#include <utility>
#include <algorithm>

class Kitchen
{
    public:
    const Unit& register_unit(Unit unit);
    const Unit* find_unit(const std::string& name) const;

    private:
    std::vector<Unit> _array;
};
