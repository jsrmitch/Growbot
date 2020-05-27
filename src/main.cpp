#include <iostream>
#include <memory>
#include <wiringPi.h>
#include "GikfunAirDiaphragmPump.h"
#include <chrono>
#include <thread>




int main()
{
    wiringPiSetup();
    const auto pin = 4;
    Library::Actuators::GikfunAirDiaphragmPump pump(pin);
    pump.Start();
    std::cout << "Hey Emma its robot Garden I turned the pump on" << std::endl;
    std::this_thread::sleep_for(std:: chrono::milliseconds(10000));
    pump.Stop();
    std::cout << "Hey Emma its robot Garden I turned the pump off" << std::endl;
    return 0;
}
