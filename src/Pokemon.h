#pragma once

#include <string>
#include <memory>

class Trainer;

// A creature that is cute and can fight other ones.
class Pokemon
{
    private:
    std::string _name;
    unsigned int _id;

    public:
    Pokemon(const std::string& name)
        : _name { name }
    {
        _id = idPokemon++;
    }

    Pokemon(const Pokemon& other)
        : _name { other._name }
        , _id { idPokemon++ }
    {}

    const Trainer* trainer() const;

    void set_trainer(const Trainer& trainer);

    Pokemon& operator=(const Pokemon& other);

    std::string name() const;
    unsigned int id() const;
    static unsigned int idPokemon;
    const Trainer* _trainer = nullptr;
};

using PokemonPtr = std::unique_ptr<Pokemon>;