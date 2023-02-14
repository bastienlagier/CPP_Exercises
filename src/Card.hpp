#pragma once

#include <string>
using namespace std;

enum class CardType {
    Monster,
    Spell,
    Trap
};

string to_string(CardType cardtype) {
    switch (cardtype) {
        case CardType::Monster:
        return "Monster";
        case CardType::Spell:
        return "Spell";
        case CardType::Trap:
        return "Trap";
        default:
        return "";
    }
}

class Card {
    public:
    Card(const string& id, CardType type)
        : _id { id }
        , _type { type }
    {}
    const string get_id() const {
        return _id;
    }
    CardType get_type() const {
        return _type;
    }
    string get_description() const {
        return _description;
    }
    string get_name() const {
        return _name;
    }
    void set_name(const string& name) {
        _name = name;
    }
    void set_description(const string& description) {
        _description = description;
    }
    void set_symbol(const string& symbol) {
        _symbol = symbol;
    }
    string get_symbol() const {
        return _symbol;
    }

    private:
    const string _id;
    string _name = "";
    string _description = "";
    const CardType _type;

    protected:
    string _symbol = "";
};