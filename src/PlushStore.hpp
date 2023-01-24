#pragma once
#include <iostream>
#include <list>
#include <Plush.hpp>
#include <optional>
#define MAX(a, b) ((a > b) ?  a : b)

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
        // valeur finale <- valeur investie + max(exp, exp * valeur investie / 100)
        unsigned int make_plush(unsigned int cost) {
            auto value = cost + MAX(_experience, _experience * cost / 100);
            if (_money >= cost || lastPlush) {
                auto plush = Plush { value };
                _stock.push_back(plush);
                _money -= cost;
                _size++;
                _experience++;
                if (!lastPlush) {
                    lastPlush = _money < cost;
                }
                else {
                    lastPlush = false;
                }
            }
            return value;
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
                    _size--;
                    return std::optional<Plush>{plush};
                }
            }
            return std::nullopt;
        }
    private:
        const std::string _name;
        unsigned int _money = 0;
        unsigned int _size = 0;
        unsigned int _experience = 0;
        bool lastPlush = false;
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
            _stock.erase(min);
            return std::optional<Plush>{*min};
        }
};