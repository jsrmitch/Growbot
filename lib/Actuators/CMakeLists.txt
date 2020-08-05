cmake_minimum_required(VERSION 3.15) # i need 3.15 for FetchContent_MakeAvailable

include(../cmake/GrpcProtoCompiler.cmake)

get_filename_component(actuator_service__fn "${CMAKE_CURRENT_SOURCE_DIR}/GardenService.proto" ABSOLUTE)
#function(GRPC_PROTO_GENERATE FN_PROTO LIB_NAME BIN_DIR)
GRPC_PROTO_GENERATE (${actuator_service__fn} GardenService ${CMAKE_CURRENT_SOURCE_DIR})