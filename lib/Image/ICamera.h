#pragma once

namespace Library::Image {

class ICamera
{
public:
    virtual void CaptureImage() = 0;
};

}