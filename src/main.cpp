#include <iostream>
#include "framework.hpp"

int main(int argc, char** argv) {
    std::string name = argv[1];
    run_algorithm(name);

    return 0;
}
