#pragma once

#include <string>
#include "Card.hpp"
using namespace std;

enum class TrapType {
    Normal,
    Continuous,
    Counter
};

string to_string(TrapType traptype) {
    switch (traptype) {
        case TrapType::Normal:
        return "Normal";
        case TrapType::Continuous:
        return "Continuous";
        case TrapType::Counter:
        return "Counter";
        default:
        return "";
    }
};

class Trap : public Card {
    public:
    Trap(const string& id, const string& name, TrapType traptype)
        : Card { id, CardType::Trap }
        , _id { id }
        , _traptype { traptype }
    {
        Card::set_name(name);
        Card::set_symbol(u8"罠");
    }
    TrapType get_trap_type() const {
        return _traptype;
    }
    string get_symbol() const {
        return u8"罠";
    }

    private:
    const string _id;
    const TrapType _traptype;
};