#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <SDL2/SDL_ttf.h>
#include <map>
#include <string>
using namespace std;


class FontManager
{
public:
    static FontManager* instance();
    void addFont(const string& fileName, const string tag, int fontSize);
    TTF_Font* getFont(string tag);
    void draw(SDL_Texture* texture, SDL_Rect pos);
    ~FontManager();

private:
    static FontManager* sInstance;
    FontManager();

    map <string, TTF_Font*> fonts;
};
#endif // FONTMANAGER_H
