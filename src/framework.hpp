#pragma once
#include <string>

enum class AlgoType { CLASSIC, THREADED, CUDA };

void run_algorithm(const std::string& name);
