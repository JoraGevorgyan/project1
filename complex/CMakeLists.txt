cmake_minimum_required(VERSION 3.12)
project(main VERSION 1.0.0)

add_library(
    complex
    complex.hpp
    compFunctions.cpp
    )

add_executable(main main.cpp)

target_link_libraries(main PRIVATE complex)

