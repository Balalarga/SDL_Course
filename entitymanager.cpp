#include "entitymanager.h"

EntityManager* EntityManager::sInstance = nullptr;

EntityManager::EntityManager()
{
}

EntityManager *EntityManager::instance()
{
    if(!sInstance)
        sInstance = new EntityManager;
    return sInstance;

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
    for(int i = 0; i < 5; i++){
        for(auto& e: entities){
            if(e.second->layer == i)
                e.second->render();
        }
    }
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

Entity& EntityManager::addEntity(string name, int layer)
{
    // TODO: log collision

    if(entities.find(name) == entities.end())
        entities[name] = new Entity(*this, name, layer);
    return *entities[name];
}
