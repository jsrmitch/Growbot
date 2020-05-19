#pragma once

namespace Library::Adapaters {

template <typename T>
class IReader
{
    private:

    public:
    T Read() = 0;
};

}
