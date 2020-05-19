#pragma once

namespace Library::Adapaters {

template <typename T>
class IReader
{
public:
    virtual T Read() = 0;
};

}
