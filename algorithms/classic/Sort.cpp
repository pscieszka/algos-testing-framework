#include "itf/Algorithm.hpp"
#include "itf/Registry.hpp"
#include <vector>
#include <algorithm>
#include <iostream>


class Sort : public Algorithm {
public:
    nlohmann::json run(const nlohmann::json& config) override {
        std::vector<int> input = config["data"].get<std::vector<int>>();
        std::sort(input.begin(), input.end());
        return {{"output", input}};
    }
};

REGISTER_ALGORITHM(Sort)
