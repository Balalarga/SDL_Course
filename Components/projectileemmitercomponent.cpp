#include "projectileemmitercomponent.h"

ProjectileEmmiterComponent::ProjectileEmmiterComponent(int speed, int angleDeg, int range, bool isLooping):
    velocity(speed),
    range(range),
    angleRad(radians(static_cast<float>(angleDeg))),
    isLooping(isLooping)
{

}

void ProjectileEmmiterComponent::init()
{
    transform = owner->getComponent<TransformComponent>();
    origin = {transform->pos.x, transform->pos.y};
    transform->velocity = {cos(angleRad)*velocity, sin(angleRad)*velocity};
}

void ProjectileEmmiterComponent::update(float dt)
{
    if(distance(transform->pos, origin) > range){
        if(isLooping){
            transform->pos = origin;
        }else{
            owner->destroy();
        }
    }
}
