#include "entitymanager.h"

EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
    for(auto& keyValue: entities){
        delete keyValue.second;
    }
}

Entity *EntityManager::getEntity(string name)
{
    if(entities.find(name) != entities.end())
        return entities[name];
    return nullptr;
}

int EntityManager::entitiesCount() const
{
    return entities.size();
}

void EntityManager::update(float dt)
{
    for(auto& e: entities)
        e.second->update(dt);
}

void EntityManager::render()
{
    for(auto& e: entities)
        e.second->render();
}

#include <iostream>

void EntityManager::printEntityList()
{
    for(auto& e: entities){
         cout<<"Entity("<<e.second->name<<")\n";
        for(auto& c: e.second->components){
            cout<<"\tCompontent<"<<c.first->name()<<">\n";
        }
    }
}

Entity& EntityManager::addEntity(string name)
{
    // TODO: log collision

    if(entities.find(name) == entities.end())
        entities[name] = new Entity(*this, name);
    return *entities[name];
}
