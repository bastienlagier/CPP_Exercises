#pragma once

#include "Pokemon.h"
#include <memory>

// A ball where a Pokemon sleeps.
class Pokeball {
    public:
    void store(PokemonPtr pokemon);
    bool empty() const;
    const Pokemon& pokemon() const;
    PokemonPtr steal();

    private:
    PokemonPtr _pokemon = nullptr;
};