#ifndef APPLICATION_H
#define APPLICATION_H

#include <GxApplication/GxApplication.h>

#include <GxGraphics/GxDisplaySettings.h>

#include <pcx/scoped_ptr.h>

#include "graphics/Graphics.h"

#include "debug/FpsCounter.h"

class Mode;

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

    pcx::scoped_ptr<Mode> mode;
};

#endif // APPLICATION_H
