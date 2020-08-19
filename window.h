#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

#include <string>
using namespace std;

#include "utils.h"

class Window
{
public:
    static SDL_Renderer* renderer;

    Window(const string& title, iSize size,
           iPoint pos = {SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED});
    ~Window();

    void show();
    void hide();
    void setClearColor(SDL_Color color);
    void clear();
    void swapBuffers();

private:
    SDL_Window* window;

    iSize windowSize;
    iPoint windowPos;
    SDL_Color windowClearColor;
};

#endif // WINDOW_H
