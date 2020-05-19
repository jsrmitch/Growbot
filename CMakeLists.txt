cmake_minimum_required(VERSION 3.13)

# Set the project name to your project name, my project isn't very descriptive
project(robotgarden VERSION 1.0
                    DESCRIPTION "System to monitor and maintain home garden"
                    LANGUAGES CXX)

include(cmake/Conan.cmake)
run_conan()

add_subdirectory(lib)
find_library(wiringPi_LIB wiringPi)
add_executable(garden src/main.cpp)

target_compile_features(garden PRIVATE cxx_std_17)

target_link_libraries(garden
  PRIVATE
    CONAN_PKG::fmt
    Sensors
    Adapters
    "${wiringPi_LIB}"
)
    