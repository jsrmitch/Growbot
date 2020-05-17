#include "MoistureSensor.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>

MoisureSensor::MoistureSensor()
    : m_running(true)
{
    wiringPiSetup();
    m_fd = wiringPiI2CSetup(ADCDEVICEID);
    m_readSensor = std::thread(ReadSensor);
}

MoisureSensor::~MoistureSensor()
{
    m_running = false;
    if(m_readSensor.joinable())
    {
        m_readSensor.join();
    }
}

void MoisureSensor::ReadSensor()
{
    while(m_running)
    {
        const auto reg{0};
        const auto data{wiringPiI2CReadReg16(m_fd, reg)}
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int MoisureSensor::Moisture()
{
    return m_moisture;
}
