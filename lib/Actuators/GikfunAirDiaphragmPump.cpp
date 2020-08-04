#include "GikfunAirDiaphragmPump.h"
#include <wiringPi.h>

namespace Library::Actuators {
    
void GikfunAirDiaphragmPump::Start(const int pin)
{
    digitalWrite(pin, HIGH);
}

void GikfunAirDiaphragmPump::Stop(const int pin)
{
    digitalWrite(pin, LOW);
}

bool GikfunAirDiaphragmPump::Running(const int pin)
{
    return digitalRead(pin) == 1; // im not an animal brad I dont do implicit casting
}

}