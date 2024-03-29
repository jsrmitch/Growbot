#include "NoyitoAdc.h"
#include <wiringPiI2C.h>
#include <chrono>
#include <thread>
#include "NoyitoAdcReader.h"

namespace Library::Adapters {

NoyitoAdc::NoyitoAdc(uint8_t i2cAddress)
    : m_i2cAddress(i2cAddress)
    , m_conversionDelay(ADS1015_CONVERSIONDELAY)
    , m_gain(GAIN_ONE)
{
    m_fd = wiringPiI2CSetup(m_i2cAddress);
}

uint16_t NoyitoAdc::readADC_SingleEnded(uint8_t channel)
{
    if(channel > 3) // Noyito4Channel ADC only has 4 channels
    {
        return 0;
    }
     // Start with default values
  uint16_t config =
      ADS1015_REG_CONFIG_CQUE_NONE |    // Disable the comparator (default val)
      ADS1015_REG_CONFIG_CLAT_NONLAT |  // Non-latching (default val)
      ADS1015_REG_CONFIG_CPOL_ACTVLOW | // Alert/Rdy active low   (default val)
      ADS1015_REG_CONFIG_CMODE_TRAD |   // Traditional comparator (default val)
      ADS1015_REG_CONFIG_DR_1600SPS |   // 1600 samples per second (default)
      ADS1015_REG_CONFIG_MODE_SINGLE;   // Single-shot mode (default)

  // Set PGA/voltage range
  config |= m_gain;

  // Set single-ended input channel
  switch (channel) {
    case (0):
        config |= ADS1015_REG_CONFIG_MUX_SINGLE_0;
        break;
    case (1):
        config |= ADS1015_REG_CONFIG_MUX_SINGLE_1;
        break;
    case (2):
        config |= ADS1015_REG_CONFIG_MUX_SINGLE_2;
        break;
    case (3):
        config |= ADS1015_REG_CONFIG_MUX_SINGLE_3;
        break;
    }

  // Set 'start single-conversion' bit
  config |= ADS1015_REG_CONFIG_OS_SINGLE;

  // Write config register to the ADC
  const auto ret = wiringPiI2CWriteReg16(m_fd, ADS1015_REG_POINTER_CONFIG, config);

  // Wait for the conversion to complete
  std::this_thread::sleep_for(std::chrono::milliseconds(m_conversionDelay));

  // Read the conversion results
  return wiringPiI2CReadReg16(m_fd, ADS1015_REG_POINTER_CONVERT);
}

std::unique_ptr<IReader<uint16_t>> NoyitoAdc::Reader(uint8_t channel)
{
    return std::make_unique<NoyitoAdcReader>(shared_from_this(), channel);
}

}