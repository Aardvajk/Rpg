#include "Graphics.h"

Graphics::Graphics(HWND hw, const Gx::DisplaySettings &settings) : device(hw, settings), size(settings.size)
{
}

Graphics::~Graphics()
{
}

void Graphics::reset()
{
    for(auto &r: resources)
    {
        if(r.isDeviceBound()) r.release();
    }

    device.reset();

    for(auto &r: resources)
    {
        if(r.isDeviceBound()) r.reset(device);
    }

    deviceReset();
}

