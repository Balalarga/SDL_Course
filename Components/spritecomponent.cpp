#include "spritecomponent.h"
#include "transformcomponent.h"
#include "game.h"

SpriteComponent::SpriteComponent(string textureId):
    texture(TextureManager::instance()->getSprite(textureId))
{}
SpriteComponent::SpriteComponent(string textureId, int animFrames, int frameSpeed,
                bool hasDirection, bool isFixed):
    texture(TextureManager::instance()->getSprite(textureId)),
    isAnimated(true),
    isFixed(isFixed)
{
    if(hasDirection){
        animations["down"] = new Animation(0, animFrames, frameSpeed);
        animations["right"] = new Animation(1, animFrames, frameSpeed);
        animations["left"] = new Animation(2, animFrames, frameSpeed);
        animations["up"] = new Animation(3, animFrames, frameSpeed);
        play("down");
    }else{
        animations["sinleAnim"] = new Animation(0, animFrames, frameSpeed);
        play("sinleAnim");
    }
}
SpriteComponent::~SpriteComponent(){
    for(auto& a: animations){
        delete a.second;
    }
}
void SpriteComponent::play(string animName){
    currentAnim = animations[animName];
}

void SpriteComponent::init(){
    transform = owner->getComponent<TransformComponent>();
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = transform->size.y;
    srcRect.h = transform->size.y;
}

void SpriteComponent::update(float dt){
    (void)dt;
    if(isAnimated){
        srcRect.x = srcRect.w*
                static_cast<int>((SDL_GetTicks()/currentAnim->animSpeed)%currentAnim->animFrames);
        srcRect.y = transform->size.x * currentAnim->animIndex;
    }

    destRect.x = static_cast<int>(transform->pos.x);
    destRect.y = static_cast<int>(transform->pos.y);
    destRect.w = transform->size.x * transform->scale.x;
    destRect.h = transform->size.y * transform->scale.y;
    if(!isFixed){
        destRect.y -= Game::camera.y;
        destRect.x -= Game::camera.x;
    }
}

void SpriteComponent::render(){
    TextureManager::instance()->draw(texture, srcRect, destRect, spriteFlip);
}
