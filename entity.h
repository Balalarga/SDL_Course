#ifndef ENTITY_H
#define ENTITY_H

#include <map>
#include <string>
using namespace std;

#include "component.h"

class EntityManager;

class Entity
{
    friend class EntityManager;

public:
    string name;
    int layer;

    Entity(EntityManager& manager);
    Entity(EntityManager& manager, string name, int layer);
    ~Entity();

    template<typename T, typename... TArgs>
    T* addComponent(TArgs&&... args){
        T* component(new T(forward<TArgs>(args)...));
        component->owner = this;
        components[&typeid(*component)] = component;
        component->init();
        return component;
    }
    template<class T>
    T* getComponent(){
        return static_cast<T*>(components[&typeid(T)]);
    }
    template<class T>
    bool hasComponent(){
        return components.find(&typeid(T)) != components.end();
    }

    void update(float dt);
    void render();
    void destroy();

    bool isActive() const;

protected:
    EntityManager& manager;
    map<const type_info*, Component*> components;
    bool active = true;
};

#endif // ENTITY_H
