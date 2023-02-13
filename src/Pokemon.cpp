#include "Pokemon.h"
#include <string>


std::string Pokemon::name() const {
    return _name;
}

unsigned int Pokemon::id() const {
    return _id;
}

Pokemon& Pokemon::operator=(const Pokemon& other) {
    if (this != &other) {
        _name = other._name;
    }
    return *this;
}

unsigned int Pokemon::idPokemon = 0;

const Trainer* Pokemon::trainer() const {
    return _trainer;
}

void Pokemon::set_trainer(const Trainer& trainer) {
    _trainer = &trainer;
}