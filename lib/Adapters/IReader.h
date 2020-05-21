#pragma once

namespace Library::Adapters {

template <typename T>
class IReader
{
public:
    virtual T Read() = 0;
};

}
