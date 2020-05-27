#pragma once

#include "ICamera.h"

namespace Library::Image {

class PiCam : public ICamera
{
public:
    void CaptureImage() override;
};

}