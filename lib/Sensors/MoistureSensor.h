#pragma once
#include "IAdc.h"
#include <atomic>
#include <thread>
#include <memory> //unique_ptr

namespace GardenRobot {
namespace Library {
namespace Sensors {

class MoistureSensor
{
private:
    std::atomic<int> m_moisture;
    std::thread m_readSensor;
    std::unique_ptr<Adapters::IAdc> m_adc;

public:
    MoistureSensor(std::unique_ptr<Adapters::IAdc> adc);
    ~MoistureSensor();

    void AgregateSensorData();

    /// <summary>
    /// Returns agregated moisture reading from Capacitive Soil Moisture Sensor
    /// <summary>
    int Moisture();
};

}
}
}