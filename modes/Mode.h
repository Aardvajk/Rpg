#ifndef MODE_H
#define MODE_H

class Graphics;

class Mode
{
public:
    virtual ~Mode();

    virtual bool update(float delta) = 0;
    virtual void render(Graphics &graphics, float blend) = 0;
};

#endif // MODE_H
