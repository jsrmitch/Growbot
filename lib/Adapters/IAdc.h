#pragma once

#include <stdint.h>

class IAdc
{
private:

protected:
    int m_fd;
public:
    virtual uint16_t readADC_SingleEnded(uint8_t channel) = 0;
};