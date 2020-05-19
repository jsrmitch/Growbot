#pragma once

namespace Library {
namespace Sensors {

template <typename T>
class IAnalogueSensor
{

public:
    using value_type = T;
    virtual T Read() = 0;
};

}
}