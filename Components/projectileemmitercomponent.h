#ifndef PROJECTILEEMMITERCOMPONENT_H
#define PROJECTILEEMMITERCOMPONENT_H

#include "component.h"
#include "transformcomponent.h"
#include "glm/glm.hpp"
using namespace glm;

class ProjectileEmmiterComponent: public Component
{
public:
    ProjectileEmmiterComponent(int speed, int angleDeg,
                               int range, bool isLooping);

    void update(float dt) override;
    void render() override;
    void init() override;

private:
    TransformComponent* transform;
    vec2 origin;
    int velocity;
    int range;
    float angleRad;
    bool isLooping;
};

#endif // PROJECTILEEMMITERCOMPONENT_H
