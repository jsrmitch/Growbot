#pragma once

#include "IReader.h"
#include <cstdint>
#include <memory>

namespace Library::Adapaters {

class NoyitoAdcReader : public IReader<uint16_t>
{
public:
    NoyitoAdcReader(std::shared_ptr<NoyitoAdc> adc, const uint8_t channel);

    uint16_t Read();

private:
    uint8_t m_channel;
    std::shared_ptr<NoyitoAdc> m_adc;
};

}

