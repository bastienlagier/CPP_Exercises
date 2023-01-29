#pragma once
#include <iostream>
#include <Plush.hpp>
#include <PlushStore.hpp>
#include <list>

class Kid {
    private:
    const std::string _name;
    unsigned int _money;
    std::list<Plush> plush_list = {};

    public:
    Kid(const std::string name, unsigned int money) 
        : _name { name }
        , _money { money }
    {}

    unsigned int get_money() const {
        return _money;
    } 

    std::string get_name() const {
        return _name;
    }

    void buy_plush(PlushStore& plush_store) {
        auto optionalPlush = plush_store.buy(_money);
        if (optionalPlush.has_value()) {
            auto plush = optionalPlush.value();
            _money -= plush.get_cost();
            plush_list.push_back(plush);          
        }
    }
};

std::ostream& operator<< (std::ostream &out, Kid const& kid) {
    out << kid.get_name() << " has " << kid.get_money(); 
    out << " euros.";
    return out;
}