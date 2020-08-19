#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <map>
#include <string>
using namespace std;

#include "entity.h"

class EntityManager
{
public:
    EntityManager();
    ~EntityManager();
    Entity& addEntity(string name);
    Entity* getEntity(string name);
    int entitiesCount() const;
    void update(float dt);
    void render();
    void printEntityList();

private:
    map<string, Entity*> entities;
};

#endif // ENTITYMANAGER_H
