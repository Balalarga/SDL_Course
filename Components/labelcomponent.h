#ifndef LABELCOMPONENT_H
#define LABELCOMPONENT_H

#include <SDL2/SDL_ttf.h>
#include "component.h"
#include "fontmanager.h"
#include "game.h"

class LabelComponent: public Component
{
public:
    LabelComponent(ivec2 pos, string text, string fontFamily, SDL_Color color);

    void render() override;
    void init() override;
    void update(float dt) override;
    void setText(string text, string fontFamily);

private:
    SDL_Rect pos;
    string text;
    string fontFamily;
    SDL_Color fontColor;
    SDL_Texture* texture;

};

#endif // LABELCOMPONENT_H
