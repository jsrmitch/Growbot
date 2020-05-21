#include <iostream>
#include <fmt/format.h>
#include "NoyitoAdc.h"
#include "MoistureSensor.h"
#include <memory>
#include <wiringPi.h>


int main()
{
    wiringPiSetup();
    auto noyitoAdc = std::make_shared<Library::Adapters::NoyitoAdc>();
    const uint8_t channel = 0;
    Library::Sensors::MoistureSensor moistureSensor(noyitoAdc->Reader(channel));
    //std::cout << moistureSensor.Read();
    return 0;
}
