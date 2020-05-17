add_library(Sensors Sensors/MoistureSensor.cpp)
target_include_directories(Sensors PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Sensors)

add_library(Adapters Adapters/Noyito4ChannelAdc.cpp)
target_include_directories(Adapters PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Adapters)