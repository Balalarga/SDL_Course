#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <SDL2/SDL.h>
#include <string>
#include <map>
using namespace std;

#include "../component.h"
#include "../texturemanager.h"
#include "transrormcomponent.h"
#include "animation.h"

class SpriteComponent: public Component
{
public:
    SpriteComponent(string textureId):
        texture(TextureManager::instance()->getSprite(textureId))
    {}
    SpriteComponent(string textureId, int animFrames, int frameSpeed,
                    bool hasDirection, bool isFixed):
        texture(TextureManager::instance()->getSprite(textureId)),
        isAnimated(true),
        isFixed(isFixed)
    {
        if(hasDirection){
            animations["Down"] = new Animation(0, animFrames, frameSpeed);
            animations["Right"] = new Animation(1, animFrames, frameSpeed);
            animations["Left"] = new Animation(2, animFrames, frameSpeed);
            animations["Up"] = new Animation(3, animFrames, frameSpeed);
            play("Down");
        }else{
            animations["sinleAnim"] = new Animation(0, animFrames, frameSpeed);
            play("sinleAnim");
        }
    }
    ~SpriteComponent(){
        for(auto& a: animations){
            delete a.second;
        }
    }
    void play(string animName){
        currentAnim = animations[animName];
    }

    void init() override{
        transform = owner->getComponent<TransrormComponent>();
        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.w = transform->size.h;
        srcRect.h = transform->size.h;
    }

    void update(float dt) override{
        (void)dt;
        if(isAnimated){
            srcRect.x = srcRect.w*
                    static_cast<int>((SDL_GetTicks()/currentAnim->animSpeed)%currentAnim->animFrames);
        }
        srcRect.y = transform->size.w * currentAnim->animIndex;

        destRect.x = static_cast<int>(transform->pos.x);
        destRect.y = static_cast<int>(transform->pos.y);
        destRect.w = transform->size.w * transform->scale.w;
        destRect.h = transform->size.h * transform->scale.h;
    }

    void render() override{
        TextureManager::instance()->draw(texture, srcRect, destRect, spriteFlip);
    }

private:
    TransrormComponent* transform;
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
