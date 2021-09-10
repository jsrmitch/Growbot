cmake_minimum_required(VERSION 3.15) # i need 3.15 for FetchContent_MakeAvailable

# Set the project name to your project name, my project isn't very descriptive
project(Growbot VERSION 1.0
                    DESCRIPTION "System to monitor and maintain home garden"
                    LANGUAGES CXX)

include(FetchContent)

# FetchContent_Declare(
#     gRPC
#         GIT_REPOSITORY https://github.com/grpc/grpc
#         GIT_TAG        v1.40.0
# )
# set(FETCHCONTENT_QUIET OFF)
# FetchContent_MakeAvailable(gRPC)

FetchContent_Declare(
    pigpio
        GIT_REPOSITORY https://github.com/jsrmitch/pigpio
        GIT_TAG        fetchContent
)
set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(pigpio)

#add_subdirectory(lib)

# find_package(Threads REQUIRED)
# find_library(LIBRT rt) 
# if(LIBRT)
#     target_link_libraries(pigpio ${LIBRT} Threads::Threads)
# endif()

add_executable(Growbot src/main.cpp)

target_compile_features(Growbot PRIVATE cxx_std_11) # rasp pi tool chain is on GNU 4.9.3

target_link_libraries(Growbot
  PRIVATE
    pigpio
    # Sensors
    # Adapters
    # Actuators
    # Image
    # grpc++
)
    