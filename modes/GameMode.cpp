#include "GameMode.h"

#include "graphics/Graphics.h"

GameMode::GameMode()
{
}

bool GameMode::update(float delta)
{
    return true;
}

void GameMode::render(Graphics &graphics, float blend)
{
    graphics.device.clear(Gx::Color::fromInts(130, 178, 206), 1.0f);
}
