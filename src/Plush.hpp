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
};