#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <glm/glm.hpp>
using namespace glm;

#include <string>
using namespace std;


class Window
{
public:
    static SDL_Renderer* renderer;

    Window(const string& title, ivec2 size,
           ivec2 pos = {SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED});
    ~Window();

    void show();
    void hide();
    void setClearColor(SDL_Color color);
    void clear();
    void swapBuffers();

    int width() const;
    int height() const;

private:
    SDL_Window* window;

    ivec2 windowSize;
    ivec2 windowPos;
    SDL_Color windowClearColor;
};

#endif // WINDOW_H
