#pragma once

#include <atomic>

class MoistureSensor
{
private:
    static constexpr auto ADCDEVICEID {0x48};
    int m_fd;
    std::atomic<int> m_moisture;
    std::atomic<bool> m_running;
    std::thread m_readSensor;

public:
    MoistureSensor();
    ~MoistureSensor();

    void ReadSensor();

    /// <summary>
    /// Returns agregated moisture reading from Capacitive Soil Moisture Sensor
    /// <summary>
    int Moisture();
};