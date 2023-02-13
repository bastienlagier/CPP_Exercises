#include "Pokedex.h"

void Pokedex::add(const Pokemon& pokemon) {
    _pokemons_by_name[pokemon.name()].push_back(&pokemon);
}

const std::vector<const Pokemon*>& Pokedex::find(const std::string& name) const {
    const auto it = _pokemons_by_name.find(name);
    return it == _pokemons_by_name.end() ? empty_list : it->second;
}