#include "MoistureSensor.h"
#include <chrono>

namespace Library::Sensors {

MoistureSensor::MoistureSensor(){}

MoistureSensor::~MoistureSensor(){}

MoistureSensor::value_type MoistureSensor::Read()
{
    return 0.0;
}

}