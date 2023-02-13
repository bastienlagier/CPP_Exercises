#pragma once

#include "Pokemon.h"

#include <vector>

// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.

class Trainer;

class PC
{
    public:
    std::vector<PokemonPtr>& pokemons();
    void transfer(PokemonPtr pokemon);
    PokemonPtr steal(Trainer& trainer, const std::string& name);

    private:
    std::vector<PokemonPtr> _pokemons;
};
