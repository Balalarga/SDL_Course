#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include <string>
using namespace std;

#include "entity.h"

class EntityManager
{
public:
    EntityManager();
    ~EntityManager();
    Entity& addEntity(string name);

private:
    vector<Entity*> entities;
};

#endif // ENTITYMANAGER_H
