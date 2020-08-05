#include "GenericPump.h"
#include <wiringPi.h>

namespace Library::Actuators {
    
void GenericPump::Start(const int pin)
{
    digitalWrite(pin, HIGH);
}

void GenericPump::Stop(const int pin)
{
    digitalWrite(pin, LOW);
}

bool GenericPump::Running(const int pin)
{
    return digitalRead(pin) == 1; // im not an animal brad I dont do implicit casting
}

}