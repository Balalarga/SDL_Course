#ifndef GAME_H
#define GAME_H

#include <include/SDL2/SDL.h>
#include <include/SDL2/SDL_image.h>

#include "./window.h"
#include "utils.h"
#include "./entitymanager.h"
#include "Components/transrormcomponent.h"
#include <Components/spritecomponent.h>

class Game
{
public:
    static SDL_Renderer* getRenderer();

    Game();
    ~Game();
    bool initSDL(int flags = SDL_INIT_EVERYTHING);
    bool initIMG(int flags = IMG_INIT_JPG|IMG_INIT_PNG);
    bool initLogic();
    bool createMainWindow(Window* window);
    bool isRunning();

    void render();
    void update(float dt);
    void handleEvents();
    void stop();
    void start();

private:
    EntityManager entityManager;
    Window* mainWindow = nullptr;
    bool running = false;

    void loadLevel(int i);
};

#endif // GAME_H
