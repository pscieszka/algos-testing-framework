cmake_minimum_required(VERSION 3.18)
project(AlgoFramework LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB_RECURSE CLASSIC_SRC "algorithms/classic/*/*.cpp")
file(GLOB_RECURSE THREADED_SRC "algorithms/threaded/*/*.cpp")
file(GLOB_RECURSE CUDA_SRC "algorithms/cuda/*/*.cu")

add_executable(algo src/main.cpp ${CLASSIC_SRC} ${THREADED_SRC} ${CUDA_SRC})
