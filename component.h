#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;

class Component
{
public:
    Entity* owner;
    virtual ~Component();
    virtual void init();
    virtual void update(float dt);
    virtual void render();

};

#endif // COMPONENT_H
