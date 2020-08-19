#include <iostream>
using namespace std;

#include "game.h"

int main(int argc, char** argv)
{
    (void)argc; (void)argv;
    Game game;

    game.initSDL();
    cout<<"Init sdl\n";

    game.initIMG();
    cout<<"Init img\n";

    game.createMainWindow(new Window("Window", {800, 600}));
    cout<<"Create main window\n";

    game.initLogic();
    cout<<"Init logic\n";

    game.start();
    cout<<"Start game\n";

    float fps = 60.f;
    float frameTime = 1000.f/fps;
    float frameStart;
    float framePassed;

    while(game.isRunning()){
        frameStart = SDL_GetTicks();
        game.handleEvents();
        game.update(frameTime);
        game.render();
        framePassed = SDL_GetTicks() - frameStart;
        if(frameTime > framePassed){
            SDL_Delay(frameTime - framePassed);
        }
    }

    return 0;
}
