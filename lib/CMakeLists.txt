# Adapters
add_library(Adapters Adapters/NoyitoAdc.cpp Adapters/NoyitoAdcReader.cpp)
target_include_directories(Adapters PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Adapters)
target_link_libraries(Adapters PRIVATE "${wiringPi_LIB}" pthread)

# Sensors
add_library(Sensors Sensors/MoistureSensor.cpp)
target_include_directories(Sensors PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Sensors)
target_link_libraries(Sensors PRIVATE Adapters)

# Actuators
add_library(Actuators Actuators/GenericPump.cpp)
target_include_directories(Actuators PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Actuators)
target_link_libraries(Adapters PRIVATE "${wiringPi_LIB}")

# Image
add_library(Image Image/PiCam.cpp)
target_include_directories(Image PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Image)

