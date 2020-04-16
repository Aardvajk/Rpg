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
    graphics.device.clear({ 0.3f, 0.7f, 0.9f }, 1.0f);
}
