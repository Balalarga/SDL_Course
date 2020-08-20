#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <SDL2/SDL.h>
#include <string>
#include <map>
using namespace std;

#include "texturemanager.h"
#include "animation.h"
#include "component.h"

class TransformComponent;

class SpriteComponent: public Component
{
public:
    SpriteComponent(string textureId);
    SpriteComponent(string textureId, int animFrames, int frameSpeed,
                    bool hasDirection, bool isFixed);
    ~SpriteComponent();
    void play(string animName);

    void init() override;
    void update(float dt) override;
    void render() override;

private:
    TransformComponent* transform;
    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
    map<string, Animation*> animations;
    Animation* currentAnim;
    bool isAnimated = false;
    bool isFixed = false;
};

#endif // SPRITECOMPONENT_H
