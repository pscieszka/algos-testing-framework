#include "framework.hpp"
#include <nlohmann/json.hpp>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <ctime>

namespace fs = std::filesystem;
using json = nlohmann::json;

AlgoType parse_algo_type(const std::string& type_str) {
    if (type_str == "classic") return AlgoType::CLASSIC;
    if (type_str == "threaded") return AlgoType::THREADED;
    if (type_str == "cuda") return AlgoType::CUDA;
    return AlgoType::CLASSIC; 
}

void run_algorithm(const std::string& name) {
    std::string json_path;
    for (const auto& category : {"classic", "threaded", "cuda"}) {
        std::string try_path = "algorithms/" + std::string(category) + "/" + name + ".json";
        if (fs::exists(try_path)) {
            json_path = try_path;
            break;
        }
    }

    std::ifstream f(json_path);
    json config;
    f >> config;

    AlgoType type = parse_algo_type(config["type"].get<std::string>());

    time_t now = time(0);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%dT%H-%M-%S", localtime(&now));
    std::string log_file = "logs/" + name + "_" + buf + ".log";
    std::ofstream log(log_file);
}
