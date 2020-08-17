#include <iostream>
using namespace std;

#include "game.h"

int main(int argc, char** argv)
{
    Game game;
    game.initSDL();
    game.initIMG();
    game.createMainWindow(new Window("Window", {800, 600}));
    game.start();

    while(game.isRunning()){
        game.handleEvents();
        game.update();
        game.render();
    }

    return 0;
}
