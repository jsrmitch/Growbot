cmake_minimum_required(VERSION 3.10)

project(robotgarden VERSION 1.0.0 LANGUAGES CXX)

target_include_directories(robotgarden
    PUBLIC
        ${PROJECT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(robotgarden PRIVATE cxx_std_17)

add_executable(robotgarden
    src/main.cpp
)
