#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "modes/Mode.h"

class GameMode : public Mode
{
public:
    GameMode();

    virtual bool update(float delta) override;
    virtual void render(Graphics &graphics, float blend) override;
};

#endif // GAMEMODE_H
