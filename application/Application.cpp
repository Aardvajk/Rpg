#include "Application.h"

#include <GxCore/GxTimer.h>

#include <pcx/str.h>

#include "modes/GameMode.h"

#include "debug/DebugText.h"
#include "debug/MemUsage.h"

Application::Application(const Gx::Point &position, const Gx::DisplaySettings &settings) : Gx::Application(position, settings.size), graphics(hwnd(), settings)
{
    DebugText::acquire(graphics);

    mode = new GameMode();

    show();
}

Application::~Application()
{
    DebugText::release();
}

int Application::exec()
{
    Gx::Timer timer;

    const float delta = 1.0f / 60.0f;
    float accumulator = delta;

    while(loop())
    {
        if(!graphics.device.isOk())
        {
            if(graphics.device.isReadyToReset())
            {
                graphics.reset();
            }
        }

        if(graphics.device.isOk())
        {
            accumulator += timer.elapsed(Gx::Timer::Flag::Restart);
            update(accumulator, delta);
        }
    }

    return 0;
}

void Application::update(float &accumulator, float delta)
{
    while(accumulator >= delta)
    {
        fps.update(delta);

        if(!mode->update(delta))
        {
            close();
            return;
        }

        accumulator -= delta;
    }

    fps.frame();

    graphics.device.begin();

    mode->render(graphics, accumulator / delta);
    renderDebugInfo();

    graphics.device.end();
}

void Application::renderDebugInfo()
{
    auto s = pcx::str("FPS:", fps.framesPerSecond(), " Mem:", MemUsage::current(), "mb Peak:", MemUsage::peak(), "mb");

    DebugText::draw(graphics.size.width - (DebugText::width(s) + 2), graphics.size.height - (DebugText::height() + 2), s);
}
