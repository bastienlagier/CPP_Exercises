#include <iostream>
#include <set>
#include <sstream>
#include <map>
#include <list>

using namespace std;

std::set<std::string> make_exit_commands() {
    return { "q", "e", "exit", "quit" };
}

void print_map(std::map<std::string, std::string>& map) {
    for (auto it = map.begin(); it != map.end(); ++it) {
        std::cout << it->first << " -> " << it->second << std::endl;
    }
}

void print_list(std::list<string> history) {
    for (auto it = history.begin(); it != history.end(); ++it) {
        std::cout << *it << endl;
    }
}

int main() {
    auto command = std::string();
    auto function = std::string();
    bool running = true;
    std::list<string> history = {};
    std::map<std::string, std::string> translate = std::map<std::string, std::string>();

    std::cout << "This is a translator" << std::endl;

    while (running) {
        getline(cin, command);

        if (make_exit_commands().count(command) > 0) {
            running = false;
        }
        std::stringstream cmdStream(command);
        
        getline(cmdStream, function, ' ');

        if (!function.compare("add")) {
            auto w1 = std::string();
            auto w2 = std::string();

            getline(cmdStream, w1, ' ');
            getline(cmdStream, w2);
            translate.insert_or_assign(w1, w2);
            std::cout << w1 << " => " << w2 << endl;
            history.push_back("add " + w1 + " " + w2);
        }
        else if (!function.compare("translate")) {
            auto word = std::string();
            while (getline(cmdStream, word, ' ')) {
                auto it  = translate.find(word);
                if (it == translate.end()) {
                    std::cout << "??? ";
                }
                else {
                    std::cout << it->second << " ";
                }
            }
            std::cout << endl;
            
        }
        else if (!function.compare("print")) {
            print_map(translate);
        }
        else if (!function.compare("history")) {
            print_list(history);
        }

    }
    return 0;
}