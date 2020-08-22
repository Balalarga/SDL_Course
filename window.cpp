#include "window.h"

SDL_Renderer* Window::renderer = nullptr;

Window::Window(const string &title, ivec2 size, ivec2 pos):
    windowSize(size),
    windowPos(pos),
    windowClearColor({100, 100, 100, 255})
{
    // TODO: add log information

    window = SDL_CreateWindow(title.c_str(), pos.x, pos.y, size.x, size.y, SDL_WINDOW_HIDDEN);
    if(!window)
        return;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer)
        return;
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Window::show()
{
    SDL_ShowWindow(window);
}

void Window::hide()
{
    SDL_HideWindow(window);
}

void Window::setClearColor(SDL_Color color)
{
    windowClearColor = color;
}

void Window::clear()
{
    SDL_SetRenderDrawColor(renderer,
                           windowClearColor.r,
                           windowClearColor.g,
                           windowClearColor.b,
                           windowClearColor.a);
    SDL_RenderClear(renderer);
}

void Window::swapBuffers()
{
    SDL_RenderPresent(renderer);
}

int Window::width() const
{
    return windowSize.x;
}

int Window::height() const
{
    return windowSize.y;
}
