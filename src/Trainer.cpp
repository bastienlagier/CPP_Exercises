#include "Trainer.h"


const std::string& Trainer::name() const {
    return _name;
}

const std::array<Pokeball, 6>& Trainer::pokeballs() const {
    return _pokeballs;
}

void Trainer::capture(PokemonPtr pokemon) {
    pokemon->set_trainer(*this);
    _pokedex.add(*pokemon);

    for (auto& pokeball: _pokeballs) {
        if (pokeball.empty()) {
            pokeball.store(std::move(pokemon));
            return;
        }
    }

    _pc.transfer(std::move(pokemon));
}

void Trainer::store_in_pc(size_t index) {
    _pc.transfer(_pokeballs[index].steal());
}

void Trainer::fetch_from_pc(const std::string& name) {
    for (auto& pokeball: _pokeballs) {
        if (pokeball.empty()) {
            auto pokemon = _pc.steal(*this, name);
            if (pokemon != nullptr) {
                pokeball.store(std::move(pokemon));
            }
            return;
        }
    }
}

const Pokedex& Trainer::pokedex() const {
    return _pokedex;
}