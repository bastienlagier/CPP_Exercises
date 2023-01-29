#pragma once

class Plush {
    private:
    unsigned int _cost;

    public:
    Plush(unsigned int cost) 
        : _cost { cost }
    {}

    Plush() 
        : Plush { 10 }
    {}

    unsigned int get_cost() const {
        return _cost;
    } 
    void set_cost(unsigned int cost) {
        _cost = cost;
    }

    bool operator == (const Plush& p) const { return _cost == p._cost; }
    bool operator != (const Plush& p) const { return !operator==(p); }
};