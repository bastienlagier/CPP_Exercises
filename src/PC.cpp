#include "PC.h"

#include <vector>
#include <algorithm>


std::vector<PokemonPtr>& PC::pokemons() {
    return _pokemons;
}

void PC::transfer(PokemonPtr pokemon) {
    if (pokemon != nullptr) {
        _pokemons.push_back(std::move(pokemon));
    }
}

PokemonPtr PC::steal(Trainer& trainer, const std::string& name) {
    auto it = std::find_if(_pokemons.begin(), _pokemons.end(), [&name](const auto& pokemon) { return pokemon->name() == name; });
    if (it != _pokemons.end() && (*it)->trainer() == &trainer) {
        auto pokemon = std::move(*it);
        _pokemons.erase(it);
        return pokemon;
    }
    return nullptr;
}