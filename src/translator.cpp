#include <iostream>
#include <set>
#include <sstream>
#include <fstream>
#include <map>
#include <list>

using namespace std;

std::set<std::string> make_exit_commands() {
    return { "q", "e", "exit", "quit" };
}

void print_map(std::map<std::string, std::string>& map) {
    for (auto it = map.begin(); it != map.end(); ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}

void print_list(std::list<string> history) {
    for (auto it = history.begin(); it != history.end(); ++it) {
        std::cout << *it << endl;
    }
}

void save_history(std::list<string> history, std::string filename) {
    fstream history_file;
    history_file.open(filename, ios::out);
    if (!history_file) {
        std::cerr << "History file has not been created" << endl;
    }
    else {
        std::cout << "History saved at " << filename << endl;
        for (auto it = history.begin(); it != history.end(); ++it) {
            history_file << *it << endl;
        }
        history_file.close();
    }
}

void load_history(list<string>& history, map<string, string>& translate, string filename) {
    fstream history_file;
    history_file.open(filename, ios::in);
    if (!history_file) {
        std::cerr << "History file cannot be read" << endl;
    }
    else {
        std::cout << "History loaded from " << filename << endl;
        auto cmd = std::string();
        while (getline(history_file, cmd)) {
            std::stringstream cmdStream(cmd);
            auto function = std::string();
            getline(cmdStream, function, ' ');
            if (!function.compare("add")) {
                history.push_back(cmd);
                auto w1 = std::string();
                auto w2 = std::string();
                getline(cmdStream, w1, ' ');
                getline(cmdStream, w2);
                translate.insert_or_assign(w1, w2);
            }
        }
    }
}

void remove_word(map<string, string>& translate, string word) {
    translate.erase(word);
    for (auto it = translate.begin(); it != translate.end();) {
        if (!it->first.compare(word) || !it->second.compare(word)) {
            translate.erase(it++);
        }
        else {
            ++it;
        }
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
        else if (!function.compare("save")) {
            auto filename = std::string();
            if (getline(cmdStream, filename, ' ')) {
                save_history(history, filename);
            }
        }
        else if (!function.compare("load")) {
            auto filename = std::string();
            if (getline(cmdStream, filename, ' ')) {
                load_history(history, translate, filename);
            }
        }
        else if (!function.compare("clear")) {
            translate.clear();
        }
        else if (!function.compare("remove")) {
            auto word = std::string();
            if (getline(cmdStream, word, ' ')) {
                remove_word(translate, word);
            }
        }
    }
    return 0;
}