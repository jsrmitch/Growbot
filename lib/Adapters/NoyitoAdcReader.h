#pragma once

#include "IReader.h"
#include <stdint.h>

namespace Library::Adapaters

class NoyitoAdcReader : public IReader<uint16_t>
{
    public:
    AdcReader(std::shared_ptr<NoyitoAdc> adc)
};

}

