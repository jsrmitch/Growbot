#pragma once

#include "IActuator.h"

namespace Library::Actuators {

class GenericPump : public IActuator
{
public:
    virtual void Start(const int pin) override;
    virtual void Stop(const int pin) override;
    virtual bool Running(const int pin) override;
};

}