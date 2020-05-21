#pragma once

#include "IActuator.h"

namespace Library::Actuators {

class GikfunAirDiaphragmPump : public IActuator
{
public:
    GikfunAirDiaphragmPump(const int pin);

    void Start() override;
    void Stop() override;
    bool Running() override;

private:
    int m_pin;
    bool m_running;    
};

}