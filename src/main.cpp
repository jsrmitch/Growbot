#include <iostream>
#include <fmt/format.h>
#include "Noyito4ChannelAdc.h"
#include "MoistureSensor.h"
#include <memory>
#include <wiringPi.h>


int main()
{
    wiringPiSetup();
    Library::Sensors::MoistureSensor moistureSensor(std::make_unique<Library::Adapters::Noyito4ChannelAdc>());
    std::cout << fmt::format("Value: {}", 10) << std::endl;
    return 0;
}
