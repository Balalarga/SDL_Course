#include "texturemanager.h"
#include "game.h"

#include <iostream>
using namespace std;

TextureManager* TextureManager::m_instance = nullptr;

TextureManager *TextureManager::instance()
{
    if(!m_instance)
        m_instance = new TextureManager();
    return m_instance;
}

TextureManager::TextureManager()
{
}


TextureManager::~TextureManager(){
    for(auto& i: m_sprites){
        SDL_DestroyTexture(i.second);
    }
}

void TextureManager::addSprite(string tag, const string &path)
{
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());

    if(loadedSurface){
        newTexture = SDL_CreateTextureFromSurface(Window::renderer, loadedSurface);
        if(newTexture){
            SDL_FreeSurface(loadedSurface);
        }else{
            cout<<"Surface is empty"<<tag<<"\n";
        }
    }else{
        cout<<"No "<<tag<<" file at "<<path<<"\n";
    }
    m_sprites[tag] = newTexture;
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect source, SDL_Rect dest, SDL_RendererFlip flip)
{
    if(!texture){
        return;
    }
    SDL_RenderCopyEx(Window::renderer, texture, &source, &dest, 0.0, NULL, flip);
}

SDL_Texture* TextureManager::getSprite(string tag)
{
    if(m_sprites.find(tag) == m_sprites.end()){
        return nullptr;
    }
    return m_sprites[tag];
}
