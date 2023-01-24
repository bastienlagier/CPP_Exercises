#pragma once
#include <iostream>
#include <list>
#include <Plush.hpp>
#include <optional>

class PlushStore {
    public:
        PlushStore(const std::string name)
            : _name { name }
        {}
        void loan(unsigned int amount) {
            _money += amount;
        }
        std::string get_name() const {
            return _name;
        }
        unsigned int make_plush(unsigned int cost) {
            if (_money >= cost) {
                auto plush = Plush { cost };
                _stock.push_back(plush);
                _money -= cost;
                _size++;
                _experience++;
                return cost;
            }
            return 0;
        }
        unsigned int get_wealth_amount() const {
            return _money;
        }
        unsigned int get_stock_size() const {
            return _size;
        }
        unsigned int get_debt_amount() const {
            return _money * 1.1;
        }
        unsigned int get_experience() const {
            return _experience;
        }
        std::optional<Plush> buy(unsigned int money) {
            auto optional_plush = minPlush();
            if (optional_plush.has_value()) {
                auto plush = optional_plush.value();
                if (money >= plush.get_cost()) {
                    _money += plush.get_cost();
                    // _stock.remove(plush);
                    _size--;
                    return optional_plush;
                }
            }
            return std::nullopt;
        }
    private:
        const std::string _name;
        unsigned int _money = 0;
        unsigned int _size = 0;
        unsigned int _experience = 0;
        std::list<Plush> _stock = { };
        std::optional<Plush> minPlush() {
            if (_size == 0) {
                return std::nullopt;
            }
            auto min = _stock.begin();
            for (auto it = min; it != _stock.end(); ++it) {
                if (it->get_cost() < min->get_cost()) {
                    min = it;
                }
            }
            return std::optional<Plush>{*min};
        }
};