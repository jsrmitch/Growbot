#include "MoistureSensor.h"
#include <chrono>

namespace Library::Sensors {

MoistureSensor::MoistureSensor(std::unique_ptr<Library::Adapters::IReader<uint16_t>> reader)
    : m_reader(std::move(reader))
{}

MoistureSensor::value_type MoistureSensor::Read()
{
    return static_cast<double>(m_reader->Read()); // implicit cast here, this is a uint16_t
}

}