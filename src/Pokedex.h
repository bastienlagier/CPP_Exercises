#pragma once

#include "Pokemon.h"

#include <map>
#include <string>
#include <vector>

class Pokedex {
    public:
    void add(const Pokemon& pokemon);
    const std::vector<const Pokemon*>& find(const std::string& name) const;

    private:
    static inline std::vector<const Pokemon*> empty_list;
    std::map<std::string, std::vector<const Pokemon*>> _pokemons_by_name;
};
