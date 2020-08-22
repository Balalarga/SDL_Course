#ifndef COLLISIONCOMPONENT_H
#define COLLISIONCOMPONENT_H

#include <SDL2/SDL.h>

#include "game.h"
#include "component.h"
#include "entitymanager.h"
#include "transformcomponent.h"

class ColliderComponent: public Component
{
public:
    string colliderTag;
    SDL_Rect collider;
    SDL_Rect srcRect;
    SDL_Rect dstRect;
    TransformComponent* transform;

    SDL_Texture* texture;
    bool showBox = false;

    ColliderComponent(const string& tag, int x, int y, int w, int h, string textureId);
    void init() override;
    void render() override;
    void update(float dt) override;
};

#endif // COLLISIONCOMPONENT_H
