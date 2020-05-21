#pragma once

namespace Library::Actuators {

class IActuator
{
public:
    virtual void Start() = 0;
    virtual void Stop() = 0;

    virtual bool Running() = 0;
};

}