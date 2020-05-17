#pragma once

class IAdc
{
private:
    int m_fd;
public:
    virtual int readADC_SingleEnded(uint8_t channel) = 0;
}