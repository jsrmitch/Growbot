#include "MoistureSensor.h"

namespace GardenRobot {
namespace Library {
namespace Sensors {

MoistureSensor::MoistureSensor(std::unique_ptr<Adapters::IAdc> adc)
    : m_adc(std::move(adc))
{
    
}

MoistureSensor::~MoistureSensor(){}

void AgregateSensorData()
{

}

int MoistureSensor::Moisture()
{
    return m_moisture;
}

}
}
}