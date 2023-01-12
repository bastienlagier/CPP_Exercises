#include <iostream>

int main(int argc, char **argv) {
    auto name = std::string();
    std::cout << "What's your name?" << std::endl;
    std::cin >> name;
    std::cout << "Hello " <<  name << std::endl;
    return 0;
}