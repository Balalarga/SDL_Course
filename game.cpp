#include "game.h"
#include "texturemanager.h"

SDL_Event Game::event;
SDL_Rect Game::camera = {0, 0, 0, 0};

Game::Game()
{
}

Game::~Game()
{
    if(mainWindow)
        delete mainWindow;
}

bool Game::initSDL(int flags)
{
    if(SDL_Init(flags) < 0){
        return false;
    }
    return true;
}

bool Game::initIMG(int flags)
{
    if(!(IMG_Init(flags)&flags)){
        return false;
    }
    return true;
}

void Game::loadLevel(int i){
    // Init textures
    TextureManager::instance()->addSprite("chopper", "../assets/images/chopper-spritesheet.png");
    TextureManager::instance()->addSprite("tilemap", "../assets/images/tilemap.png");
    TextureManager::instance()->addSprite("radar", "../assets/images/radar.png");

    //Create map
    map = new Map("tilemap", 2, 32);
    map->loadFrom("../assets/tilemap.map", {25, 20});

    // Create entities
    Entity& entity = EntityManager::instance()->addEntity("player", 2);
    entity.addComponent<TransformComponent>(50, 50, 0, 0,
                                            32, 32, 1, 1);
    entity.addComponent<SpriteComponent>("chopper", 2, 90, true, false);
    entity.addComponent<KeyboardComponent>(SDLK_a, SDLK_d, SDLK_w, SDLK_s);

    Entity& radar = EntityManager::instance()->addEntity("radar", 3);
    radar.addComponent<TransformComponent>(mainWindow->width()-64, 0, 0, 0,
                                            64, 64, 1, 1);
    radar.addComponent<SpriteComponent>("radar", 8, 90, false, true);
}

bool Game::initLogic()
{
    loadLevel(1);
    return true;
}

bool Game::createMainWindow(Window *window)
{
    if(!mainWindow){
        mainWindow = window;
        camera.w = mainWindow->width();
        camera.h = mainWindow->height();
        return true;
    }else{
        delete window;
        return false;
    }
}

bool Game::isRunning()
{
    return running;
}

void Game::render()
{
    mainWindow->clear();

    EntityManager::instance()->render();

    mainWindow->swapBuffers();
}

void Game::update(float dt)
{
    // Cast to seconds
    EntityManager::instance()->update(dt/1000.f);
    handleCameraMovement();
}

void Game::handleCameraMovement(){
    Entity* e = EntityManager::instance()->getEntity("player");
    TransformComponent* player = e->getComponent<TransformComponent>();
    camera.x = player->pos.x - (mainWindow->width()/2);
    camera.y = player->pos.y - (mainWindow->height()/2);

    camera.x = camera.x < 0 ? 0: camera.x;
    camera.y = camera.y < 0 ? 0: camera.y;
    camera.x = camera.x > camera.w ? camera.w: camera.x;
    camera.y = camera.y > camera.h ? camera.h: camera.y;
}

void Game::handleEvents()
{
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE){
        stop();
        return;
    }
}

void Game::stop()
{
    running = false;
    mainWindow->hide();
}

void Game::start()
{
    running = true;
    mainWindow->show();
}
