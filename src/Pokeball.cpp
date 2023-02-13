#include "Pokeball.h"

bool Pokeball::empty() const {
    return _pokemon == nullptr;
}

void Pokeball::store(PokemonPtr pokemon) {
    _pokemon = std::move(pokemon);
}

const Pokemon& Pokeball::pokemon() const {
    return *_pokemon;
}

PokemonPtr Pokeball::steal() {
    return std::move(_pokemon);
}