add_library(Sensors Sensors/MoistureSensor.cpp)
target_include_directories(Sensors PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Sensors)