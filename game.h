#ifndef GAME_H
#define GAME_H



#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "window.h"

class Game
{
public:
    Game();
    ~Game();
    bool initSDL(int flags = SDL_INIT_EVERYTHING);
    bool initIMG(int flags = IMG_INIT_JPG|IMG_INIT_PNG);
    bool createMainWindow(Window* window);
    bool isRunning();

    void render();
    void update();
    void handleEvents();
    void stop();
    void start();

private:
    Window* mainWindow = nullptr;
    bool running = false;
};

#endif // GAME_H
