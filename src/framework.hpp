#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <filesystem>
#include <nlohmann/json.hpp>

#include "itf/Registry.hpp"
#include "itf/Algorithm.hpp"
#include "algorithms/classic/sort.hpp"

namespace fs = std::filesystem;
using nlohmann::json;
using Clock = std::chrono::high_resolution_clock;

std::string find_config_path(const std::string& name) {
    const std::string target_filename = name + ".json";
    const std::string base_dir = "algorithms";

    for (const auto& entry : fs::recursive_directory_iterator(base_dir)) 
    {
        if (entry.is_regular_file() && entry.path().filename() == target_filename) 
        {
            return entry.path().string();
        }
    }
    return "";

}

std::string timestamp_string() 
{
    auto now = std::chrono::system_clock::now();
    auto t = std::chrono::system_clock::to_time_t(now);
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&t), "%Y%m%d_%H%M%S");
    return oss.str();
}

void write_log(const std::string& name, double duration_ms) 
{
    std::string filename = "logs/" + name + "_" + timestamp_string() + ".log";

    std::ofstream log_file(filename);
    if (!log_file.is_open()) {
        std::cerr << "Failed to open log file: " << filename << std::endl;
        return;
    }

    log_file << "Algorithm: " << name << "\n";
    log_file << "Duration (ms): " << duration_ms << "\n";

    log_file.close();
}

void run_algorithm(const std::string& name) 
{
    std::string config_path = find_config_path(name);
    std::unique_ptr<Algorithm> algo(Registry::instance().create(name));
    std::ifstream config_file(config_path);

    json config;
    if (config_file.is_open()) 
    {
        config_file >> config;
    } 

    auto start = Clock::now();
    json result = algo->run(config);
    auto end = Clock::now();
    double duration_ms = std::chrono::duration<double, std::milli>(end - start).count();
    write_log(name, duration_ms);


}
