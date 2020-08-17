#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
using namespace std;

#include "component.h"

class Entity
{
public:
    Entity();
    ~Entity();
    void addComponent(Component* component);

protected:
    vector<Component*> components;
};

#endif // ENTITY_H
