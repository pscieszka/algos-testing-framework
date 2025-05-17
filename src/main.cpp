#include "framework.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Użycie: ./algo <nazwa_algorytmu>\n";
        return 1;
    }

    std::string name = argv[1];
    run_algorithm(name);

    return 0;
}
