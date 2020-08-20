#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <map>
#include <string>
using namespace std;

#include "entity.h"

class EntityManager
{
public:
    static EntityManager* instance();
    ~EntityManager();
    Entity& addEntity(string name, int layer);
    Entity* getEntity(string name);
    int entitiesCount() const;
    void update(float dt);
    void render();
    void printEntityList();

private:
    EntityManager();
    static EntityManager* sInstance;

    map<string, Entity*> entities;
};

#endif // ENTITYMANAGER_H
