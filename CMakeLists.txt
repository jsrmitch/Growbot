cmake_minimum_required(VERSION 3.15)

# Set the project name to your project name, my project isn't very descriptive
project(robotgarden CXX)

include(cmake/Conan.cmake)
run_conan()


add_executable(garden src/main.cpp)

target_compile_features(garden PRIVATE cxx_std_17)

target_link_libraries(garden
  PRIVATE
    CONAN_PKG::fmt
)
    