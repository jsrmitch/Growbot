#pragma once
#include "IAdc.h"
#include <atomic>
#include <thread>
#include <memory> //unique_ptr
#include "IAnalogueSensor.h"

namespace Library::Sensors {

class MoistureSensor : public IAnalogueSensor<double>
{
private:
    std::unique_ptr<Library::Adapters::IReader<uint16_t>> m_reader;

public:
    MoistureSensor(std::unique_ptr<Library::Adapters::IReader<uint16_t>> reader);

    /// <summary>
    /// Returns agregated moisture reading from Capacitive Soil Moisture Sensor
    /// <summary>
    value_type Read() override;
};

}
