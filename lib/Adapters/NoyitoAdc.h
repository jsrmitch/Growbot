#pragma once

#include "IAdc.h"
#include "ADS1015.h"
#include <cstdint>

namespace Library::Adapters {

/// <summary>
/// class for using NOYITO 4-Channel 16-Bit ADC with PGA for RPI Raspberry PI https://www.amazon.com.au/gp/product/B07PNMXR8B/ref=ppx_yo_dt_b_asin_title_o05_s00?ie=UTF8&psc=1
/// based on https://github.com/adafruit/Adafruit_ADS1X15/blob/master/Adafruit_ADS1015.h
/// beleive this is a ADS1015
/// <summary>
class NoyitoAdc : public IAdc, public std::enable_shared_from_this<NoyitoAdc>
{
private:
    // Instance-specific properties
    uint8_t m_i2cAddress;      ///< the I2C address
    uint8_t m_conversionDelay; ///< conversion deay
    adsGain_t m_gain;          ///< ADC gain

public:
    NoyitoAdc(uint8_t i2cAddress = ADS1015_ADDRESS);

    uint16_t readADC_SingleEnded(uint8_t channel) override;

    std::unique_ptr<IReader<uint16_t>> Reader(uint8_t channel) override;
};

}