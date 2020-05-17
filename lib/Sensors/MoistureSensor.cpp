#include "MoistureSensor.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>

MoisureSensor::MoistureSensor()
    : m_running(true)
{
    wiringPiSetup();
}

MoisureSensor::~MoistureSensor(){}

int MoisureSensor::Moisture()
{
    return m_moisture;
}
