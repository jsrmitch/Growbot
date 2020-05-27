cmake_minimum_required(VERSION 3.15) # i need 3.15 for FetchContent_MakeAvailable

# Set the project name to your project name, my project isn't very descriptive
project(robotgarden VERSION 1.0
                    DESCRIPTION "System to monitor and maintain home garden"
                    LANGUAGES CXX)

include(cmake/Conan.cmake)
run_conan()

include(FetchContent)
FetchContent_Declare(
  gRPC
  GIT_REPOSITORY https://github.com/grpc/grpc
  GIT_TAG        v1.28.0  # e.g v1.28.0
)
set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(gRPC)

add_subdirectory(lib)
find_library(wiringPi_LIB wiringPi)
add_executable(garden src/main.cpp)

target_compile_features(garden PRIVATE cxx_std_17)

target_link_libraries(garden
  PRIVATE
    Sensors
    Adapters
    "${wiringPi_LIB}"
    Actuators
    pthread
    Image
    grpc++  
)
    