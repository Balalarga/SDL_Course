#include "collidercomponent.h"

ColliderComponent::ColliderComponent(const string &tag, int x, int y, int w, int h, string textureId):
    colliderTag(tag),
    collider({x, y, w, h}),
    texture(TextureManager::instance()->getSprite(textureId))
{
}

void ColliderComponent::init(){
    if(owner->hasComponent<TransformComponent>()){
        transform = owner->getComponent<TransformComponent>();
        srcRect = {0, 0, transform->size.w, transform->size.h};
        dstRect = collider;
    }
}

void ColliderComponent::update(float dt){
    if(!transform)
        return;
    collider.x = static_cast<int>(transform->pos.x);
    collider.y = static_cast<int>(transform->pos.y);
    collider.w = transform->size.w*transform->scale.w;
    collider.h = transform->size.h*transform->scale.h;
    dstRect.x = collider.x-Game::camera.x;
    dstRect.y = collider.y-Game::camera.y;
}

void ColliderComponent::render()
{
    if(!showBox)
        return;
    TextureManager::instance()->draw(texture, srcRect, dstRect, SDL_FLIP_NONE);
}
