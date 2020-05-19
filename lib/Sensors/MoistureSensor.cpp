#include "MoistureSensor.h"
#include <chrono>

namespace Library {
namespace Sensors {

MoistureSensor::MoistureSensor(){}

MoistureSensor::~MoistureSensor(){}

MoistureSensor::value_type MoistureSensor::Read()
{
    return 0.0;
}

}
}