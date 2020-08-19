#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <map>
#include <string>
#include <fstream>
using namespace std;

class TextureManager
{
public:
    static TextureManager* instance();
    ~TextureManager();
    void addSprite(string tag, const string& path);
    void draw(SDL_Texture *texture, SDL_Rect source,
              SDL_Rect dest, SDL_RendererFlip flip);
    SDL_Texture* getSprite(string tag);

private:
    TextureManager();
    static TextureManager* m_instance;
    map<string, SDL_Texture*> m_sprites;
};

#endif // TEXTUREMANAGER_H
