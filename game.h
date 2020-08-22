#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <glm/glm.hpp>
using namespace glm;

#include "map.h"
#include "window.h"
#include "entitymanager.h"
#include <Components/spritecomponent.h>
#include "Components/transformcomponent.h"
#include <Components/keyboardcomponent.h>
#include <Components/collidercomponent.h>
#include <Components/labelcomponent.h>
#include <Components/projectileemmitercomponent.h>

class Game
{
public:
    static SDL_Event event;
    static SDL_Rect camera;

    Game();
    ~Game();
    bool initTTF();
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
    Window* mainWindow = nullptr;
    bool running = false;
    Map* map;

    void loadLevel(int i);
    void handleCameraMovement();
    void checkCollisions();
};

#endif // GAME_H
