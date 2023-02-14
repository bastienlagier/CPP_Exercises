#pragma once

#include <string>
#include "Card.hpp"
using namespace std;

enum class SpellType {
    Normal,
    Equip,
    Continuous,
    QuickPlay,
    Field
};

string to_string(SpellType spelltype) {
    switch (spelltype) {
        case SpellType::Normal:
        return "Normal";
        case SpellType::Equip:
        return "Equip";
        case SpellType::Continuous:
        return "Continuous";
        case SpellType::QuickPlay:
        return "Quick-Play";
        case SpellType::Field:
        return "Field";
        default:
        return "";
    }
}

class Spell : public Card {
    public:
    Spell(const string& id, const string& category, SpellType type) 
        : Card { id, CardType::Spell }
        , _id { id }
        , _category { category }
        , _type { type }
    {
        Card::set_name(category);
        Card::set_symbol(u8"魔");
    }

    SpellType get_spell_type() const {
        return _type;
    }

    string get_symbol() const {
        return Card::_symbol;
    }

    private:
    const string _id;
    const string _category;
    const SpellType _type;
};