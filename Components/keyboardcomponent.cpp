#include "keyboardcomponent.h"

KeyboardComponent::KeyboardComponent(SDL_KeyCode leftKey, SDL_KeyCode rightKey, SDL_KeyCode upKey, SDL_KeyCode downKey)
{
    keyMapping["left"] = leftKey;
    keyMapping["right"] = rightKey;
    keyMapping["up"] = upKey;
    keyMapping["down"] = downKey;
}

void KeyboardComponent::mapKey(string key, SDL_KeyCode code)
{
    keyMapping[key] = code;
}

void KeyboardComponent::init()
{
    transform = owner->getComponent<TransformComponent>();
    sprite = owner->getComponent<SpriteComponent>();
}

void KeyboardComponent::update(float dt)
{
    if(Game::event.type == SDL_KEYDOWN){
        if(Game::event.key.keysym.sym == keyMapping["left"]){
            transform->velocity.x = -100;
            transform->velocity.y = 0;
            sprite->play("left");
        }else if(Game::event.key.keysym.sym == keyMapping["right"]){
            transform->velocity.x = 100;
            transform->velocity.y = 0;
            sprite->play("right");
        }else if(Game::event.key.keysym.sym == keyMapping["up"]){
            transform->velocity.y = -100;
            transform->velocity.x = 0;
            sprite->play("up");
        }else if(Game::event.key.keysym.sym == keyMapping["down"]){
            transform->velocity.y = 100;
            transform->velocity.x = 0;
            sprite->play("down");
        }
    }else if(Game::event.type == SDL_KEYUP){
        if(Game::event.key.keysym.sym == keyMapping["left"]){
            transform->velocity.x = 0;
        }else if(Game::event.key.keysym.sym == keyMapping["right"]){
            transform->velocity.x = 0;
        }else if(Game::event.key.keysym.sym == keyMapping["up"]){
            transform->velocity.y = 0;
        }else if(Game::event.key.keysym.sym == keyMapping["down"]){
            transform->velocity.y = 0;
        }
    }
}
