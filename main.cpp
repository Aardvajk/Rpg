#include "application/Application.h"

#include <GxCore/GxWindows.h>
#include <GxCore/GxDebug.h>

#include <GxGraphics/GxDisplaySettings.h>

#include <exception>
#include <cstdlib>

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
    try
    {
        Application app({ 60, 60 }, { { 1024, 768 }, Gx::DisplaySettings::Flag::Windowed | Gx::DisplaySettings::Flag::VSync, 4 });
        return app.exec();
    }

    catch(const std::exception &e)
    {
        MessageBox(nullptr, e.what(), "Error", MB_OK);
        return 1;
    }
}

