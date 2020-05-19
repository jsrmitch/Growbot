#pragma once

namespace Library::Sensors {

template <typename T>
class IAnalogueSensor
{

public:
    using value_type = T;
    virtual T Read() = 0;
};

}