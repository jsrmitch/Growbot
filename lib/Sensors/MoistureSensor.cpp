#include "MoistureSensor.h"
#include <wiringPi.h>

MoistureSensor::MoistureSensor()
{
    wiringPiSetup();
}

MoistureSensor::~MoistureSensor(){}

int MoistureSensor::Moisture()
{
    return m_moisture;
}
