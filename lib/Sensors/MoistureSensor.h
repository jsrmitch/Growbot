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

public:
    MoistureSensor();
    ~MoistureSensor();

    /// <summary>
    /// Returns agregated moisture reading from Capacitive Soil Moisture Sensor
    /// <summary>
    value_type Read() override;
};

}
