#include "game.h"
#include "texturemanager.h"

SDL_Renderer *Game::getRenderer()
{
    return Window::renderer;
}

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


    // Create entities
    Entity& entity = entityManager.addEntity("player");
    entity.addComponent<TransrormComponent>(0, 0, 20, 20,
                                             32, 32, 1, 1);
    entity.addComponent<SpriteComponent>("chopper", 2, 90, true, false);
    entityManager.printEntityList();
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

    entityManager.render();

    mainWindow->swapBuffers();
}

void Game::update(float dt)
{
    // Cast to seconds
    entityManager.update(dt/1000.f);
}

void Game::handleEvents()
{
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT){
            stop();
            return;
        }
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
