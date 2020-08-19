#include "entity.h"
#include "entitymanager.h"

Entity::Entity(EntityManager &manager):
    manager(manager)
{
}

Entity::Entity(EntityManager &manager, string name):
    name(name),
    manager(manager)
{
}

Entity::~Entity()
{
    for(auto& pair: components){
        delete pair.second;
    }
}

void Entity::update(float dt)
{
    for(auto& pair: components){
        pair.second->update(dt);
    }
}

void Entity::render()
{
    for(auto& pair: components){
        pair.second->render();
    }
}

bool Entity::isActive() const
{
    return active;
}

void Entity::destroy(){
    active = false;
}
