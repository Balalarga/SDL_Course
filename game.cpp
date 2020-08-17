#include "game.h"

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
    mainWindow->swapBuffers();
}

void Game::update()
{

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
