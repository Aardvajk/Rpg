#include "Application.h"

#include <GxCore/GxTimer.h>

#include <pcx/str.h>

#include "debug/DebugText.h"
#include "debug/MemUsage.h"

Application::Application(const Gx::Point &position, const Gx::DisplaySettings &settings) : Gx::Application(position, settings.size), graphics(hwnd(), settings)
{
    DebugText::acquire(graphics);

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

        accumulator -= delta;
    }

    fps.frame();

    graphics.device.begin();

    graphics.device.clear({ 0.3f, 0.7f, 0.9f }, 1.0f);
    renderDebugInfo();

    graphics.device.end();
}

void Application::renderDebugInfo()
{
    auto s = pcx::str("FPS:", fps.framesPerSecond(), " Mem:", MemUsage::current(), "mb Peak:", MemUsage::peak(), "mb");

    DebugText::draw(graphics.size.width - (DebugText::width(s) + 2), graphics.size.height - (DebugText::height() + 2), s);
}
