#pragma once
#include "IAdc.h"
#include <atomic>

class MoistureSensor
{
private:
    std::atomic<int> m_moisture;

public:
    MoistureSensor();
    ~MoistureSensor();

    /// <summary>
    /// Returns agregated moisture reading from Capacitive Soil Moisture Sensor
    /// <summary>
    int Moisture();
};