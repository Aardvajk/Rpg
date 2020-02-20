#ifndef APPLICATION_H
#define APPLICATION_H

#include <GxApplication/GxApplication.h>

#include <GxGraphics/GxDisplaySettings.h>

#include "graphics/Graphics.h"

#include "debug/FpsCounter.h"

class Application : public Gx::Application
{
public:
    Application(const Gx::Point &position, const Gx::DisplaySettings &settings);
    virtual ~Application() override;

    int exec();

private:
    void update(float &accumulator, float delta);
    void renderDebugInfo();

    Graphics graphics;
    FpsCounter fps;
};

#endif // APPLICATION_H
