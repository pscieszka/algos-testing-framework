#pragma once
#include <nlohmann/json.hpp>

class Algorithm {
public:
    virtual ~Algorithm() {}
    virtual nlohmann::json run(const nlohmann::json& config) = 0;
};
