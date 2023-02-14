#pragma once

#include <string>
#include "Card.hpp"
using namespace std;

enum class Attribute {
    Dark,
    Divine,
    Earth,
    Fire,
    Light,
    Water,
    Wind
};

string to_symbol(Attribute attribute) {
    switch (attribute) {
        case Attribute::Dark:
        return u8"闇";
        case Attribute::Divine:
        return u8"神";
        case Attribute::Earth:
        return u8"地";
        case Attribute::Fire:
        return u8"炎";
        case Attribute::Light:
        return u8"光";
        case Attribute::Water:
        return u8"水";
        case Attribute::Wind:
        return u8"風";
        default:
        return u8"";
    }
}

class Monster : public Card {
    public:
    Monster(const string& id, const string& name, Attribute attribute, 
        const string& category, const unsigned int atk, const unsigned int def)
        : Card { id, CardType::Monster }
        , _id { id }
        , _attribute { attribute }
        , _category { category }
        , _atk { atk }
        , _def { def }
    {
        Card::set_name(name);
    }

    
    Attribute get_attribute() const {
        return _attribute;
    }
    unsigned int get_atk() const {
        return _atk;
    } 
    unsigned int get_def() const {
        return _def;
    }
    string get_id() const {
        return _id;
    }
    CardType get_type() const {
        return CardType::Monster;
    }
    string get_name() const {
        return _name;
    }

    private:
    const string _id;
    const string _name;
    const Attribute _attribute;
    const string _category;
    const unsigned int _atk;
    const unsigned int _def;
};