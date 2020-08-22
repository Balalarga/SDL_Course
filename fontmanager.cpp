#include "fontmanager.h"
#include "game.h"

FontManager* FontManager::sInstance;

FontManager::FontManager()
{
}

FontManager *FontManager::instance()
{
    if(!sInstance)
        sInstance = new FontManager();
    return sInstance;
}

void FontManager::addFont(const string &fileName, const string tag, int fontSize)
{
    TTF_Font* font = TTF_OpenFont(fileName.c_str(), fontSize);
    if(font)
        fonts[tag] = font;
}

void FontManager::draw(SDL_Texture *texture, SDL_Rect pos)
{
    SDL_RenderCopy(Window::renderer, texture, NULL, &pos);
}

FontManager::~FontManager()
{
    for(auto& f: fonts){
        TTF_CloseFont(f.second);
    }
}

TTF_Font* FontManager::getFont(string tag)
{
    if(fonts.find(tag) != fonts.end())
        return fonts[tag];
    return nullptr;
}
