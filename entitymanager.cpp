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

Entity &EntityManager::addEntity(string name)
{
    // TODO: log collision

    if(entities.find(name) != entities.end())
        entities[name] = new Entity;
    return *entities[name];
}
