#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H

#include "../component.h"
#include "../entitymanager.h"
#include "../texturemanager.h"
#include "game.h"
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
using namespace glm;

class TileComponent: public Component
{
public:
    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect dstRect;
    ivec2 pos;
    TileComponent(string textureId, ivec2 srcPos, ivec2 tilePos, int tileSize, int tileScale){
        texture = TextureManager::instance()->getSprite(textureId);
        srcRect = {srcPos.x, srcPos.y, tileSize, tileSize};
        dstRect = {tilePos.x, tilePos.y, tileSize*tileScale, tileSize*tileScale};
        pos = tilePos;
    }
    ~TileComponent(){
    }
    void update(float dt) override{
        dstRect.x =  pos.x - Game::camera.x;
        dstRect.y =  pos.y - Game::camera.y;
    }

    void render() override{
        TextureManager::instance()->draw(texture, srcRect, dstRect, SDL_FLIP_NONE);
    }

    void init() override{

    }
};

#endif // TILECOMPONENT_H
