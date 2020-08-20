#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include <iostream>
#include <SDL2/SDL.h>

#include "component.h"
#include "entitymanager.h"
#include "utils.h"
#include "game.h"


class TransformComponent: public Component
{
    friend class SpriteComponent;

public:
    fPoint pos;
    fPoint velocity;
    iSize size;
    iSize scale;
    TransformComponent(float posX, float posY,
                       float velX, float velY,
                       int sizeX, int sizeY,
                       int scaleX, int scaleY):
        pos({posX, posY}),
        velocity({velX, velY}),
        size({sizeX, sizeY}),
        scale({scaleX, scaleY}){}

    void init() override{

    }

    void update(float dt) override{
        pos.x += velocity.x*dt;
        pos.y += velocity.y*dt;
    }
};

#endif // TRANSFORMCOMPONENT_H
