#ifndef KEYBOARDCOMPONENT_H
#define KEYBOARDCOMPONENT_H

#include "Components/spritecomponent.h"
#include "Components/transformcomponent.h"

class KeyboardComponent: public Component
{
public:
    KeyboardComponent(SDL_KeyCode leftKey, SDL_KeyCode rightKey, SDL_KeyCode upKey, SDL_KeyCode downKey);
    void mapKey(string key, SDL_KeyCode code);
    void init() override;
    void update(float dt) override;

private:
    TransformComponent* transform;
    SpriteComponent* sprite;
    map<string, SDL_KeyCode> keyMapping;
};


#endif // KEYBOARDCOMPONENT_H
