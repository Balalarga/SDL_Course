#include "entitymanager.h"
#include <iostream>
#include "Components/collidercomponent.h"
#include "collisionmanager.h"

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

void EntityManager::printEntityList()
{
    for(auto& e: entities){
        cout<<"Entity("<<e.second->name<<")\n";
        for(auto& c: e.second->components){
            cout<<"\tCompontent<"<<c.first->name()<<">\n";
        }
    }
}

string EntityManager::checkEntityCollision(string tag)
{
    Entity* e = getEntity(tag);
    if(!e)
        return "";
    ColliderComponent* collider = e->getComponent<ColliderComponent>();
    for(auto& pair: entities){
        if(pair.second != e &&
                pair.second->hasComponent<ColliderComponent>()){
            ColliderComponent* otherCollider =
                    pair.second->getComponent<ColliderComponent>();
            if(CollisionManager::checkCollision(collider->collider, otherCollider->collider)){
                return otherCollider->colliderTag;
            }
        }
    }
    return "";
}

void EntityManager::tuggleColliderBox()
{
    for(auto& e: entities){
        if(e.second->hasComponent<ColliderComponent>()){
           e.second->getComponent<ColliderComponent>()->showBox =
                   !e.second->getComponent<ColliderComponent>()->showBox;
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
