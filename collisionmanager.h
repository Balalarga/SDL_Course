#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <SDL2/SDL.h>

class CollisionManager
{
public:
    static bool checkCollision(const SDL_Rect &a, const SDL_Rect &b);
};

#endif // COLLISIONMANAGER_H
