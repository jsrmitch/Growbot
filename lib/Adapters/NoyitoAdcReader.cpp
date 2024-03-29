#include "NoyitoAdcReader.h"

namespace Library::Adapters {

NoyitoAdcReader::NoyitoAdcReader(std::shared_ptr<NoyitoAdc> adc, const uint8_t channel)
    : m_adc{adc}
    , m_channel{channel}
{}

uint16_t NoyitoAdcReader::Read()
{
    return m_adc->readADC_SingleEnded(m_channel);
}

}
