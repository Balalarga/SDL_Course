#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

#include <string>
using namespace std;

#include "utils.h"

class Window
{
public:
    Window(const string& title, iSize size,
           iPoint pos = {SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED});
    ~Window();

    SDL_Renderer* getRenderer();

    void show();
    void hide();
    void setClearColor(SDL_Color color);
    void clear();
    void swapBuffers();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    iSize windowSize;
    iPoint windowPos;
    SDL_Color windowClearColor;
};

#endif // WINDOW_H
