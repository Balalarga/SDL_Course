#include "labelcomponent.h"

LabelComponent::LabelComponent(ivec2 pos, string text, string fontFamily, SDL_Color color):
    text(text),
    fontFamily(fontFamily),
    fontColor(color)
{
    this->pos.x = pos.x;
    this->pos.y = pos.y;
    setText(text, fontFamily);
}

void LabelComponent::render()
{
    FontManager::instance()->draw(texture, pos);
}

void LabelComponent::init()
{

}

void LabelComponent::update(float dt)
{

}

void LabelComponent::setText(string text, string fontFamily)
{
    SDL_Surface* surface = TTF_RenderText_Blended(FontManager::instance()->getFont(fontFamily), text.c_str(), fontColor);
    texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
    SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
}
