# Adapters
add_library(Adapters Adapters/Noyito4ChannelAdc.cpp)
target_include_directories(Adapters PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Adapters)
target_link_libraries(Adapters PRIVATE "${wiringPi_LIB}")

# Sensors
add_library(Sensors Sensors/MoistureSensor.cpp)
target_include_directories(Sensors PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Sensors)
target_include_directories(Sensors PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Adapters)
target_link_libraries(Sensors PRIVATE Adapters)

