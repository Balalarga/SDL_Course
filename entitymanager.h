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

private:
    map<string, Entity*> entities;
};

#endif // ENTITYMANAGER_H
