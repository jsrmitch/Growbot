#pragma once

#include <cstdint>
#include "IReader.h"
#include <memory>

namespace Library::Adapters {

class IAdc
{
private:

protected:
    int m_fd;
public:
    virtual uint16_t readADC_SingleEnded(uint8_t channel) = 0;
    virtual std::unique_ptr<IReader<uint16_t>> Reader(uint8_t channel) = 0;
};

}