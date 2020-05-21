#include "GikfunAirDiaphragmPump.h"
#include <wiringPi.h>

namespace Library::Actuators {

GikfunAirDiaphragmPump::GikfunAirDiaphragmPump(const int pin)
    : m_pin(pin)
    , m_running(false)
{
    pinMode(m_pin, OUTPUT);
}
    
void GikfunAirDiaphragmPump::Start()
{
    m_running = true;
    digitalWrite(m_pin, HIGH);
}

void GikfunAirDiaphragmPump::Stop()
{
    m_running = false;
    digitalWrite(m_pin, LOW);
}

bool GikfunAirDiaphragmPump::Running()
{
    return m_running;
}

}