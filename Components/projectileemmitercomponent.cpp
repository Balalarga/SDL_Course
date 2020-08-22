#include "projectileemmitercomponent.h"

ProjectileEmmiterComponent::ProjectileEmmiterComponent(int speed, int angleDeg, int range, bool isLooping):
    velocity(speed),
    range(range),
    angleRad(radians(static_cast<float>(angleDeg))),
    isLooping(isLooping)
{

}

void ProjectileEmmiterComponent::update(float dt)
{

}

void ProjectileEmmiterComponent::render()
{

}

void ProjectileEmmiterComponent::init()
{
    transform = owner->getComponent<TransformComponent>();
    origin = {transform->pos.x, transform->pos.y};

}
