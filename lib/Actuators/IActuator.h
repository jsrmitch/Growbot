#pragma once

namespace Library::Actuators {

class IActuator
{
public:
    virtual void Start(const int pin) = 0;
    virtual void Stop(const int pin) = 0;
    virtual bool Running(const int pin) = 0;
};

}