#include "game.h"
#include "texturemanager.h"
#include "fontmanager.h"

SDL_Event Game::event;
SDL_Rect Game::camera = {0, 0, 0, 0};

Game::Game()
{
}

Game::~Game()
{
    if(mainWindow)
        delete mainWindow;
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

bool Game::initSDL(int flags)
{
    if(SDL_Init(flags) != 0){
        return false;
    }
    return true;
}

bool Game::initTTF()
{
    if(TTF_Init() != 0){
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
    TextureManager::instance()->addSprite("tank", "../assets/images/tank-big-right.png");
    TextureManager::instance()->addSprite("radar", "../assets/images/radar.png");
    TextureManager::instance()->addSprite("bullet", "../assets/images/bullet-enemy.png");
    TextureManager::instance()->addSprite("chopper", "../assets/images/chopper-spritesheet.png");
    TextureManager::instance()->addSprite("tilemap", "../assets/images/tilemap.png");
    TextureManager::instance()->addSprite("colliderBox", "../assets/images/collision-texture.png");

    FontManager::instance()->addFont("../assets/fonts/charriot.ttf", "charriot", 14);

    //Create map
    int scale = 2;
    map = new Map("tilemap", scale, 32);
    map->loadFrom("../assets/tilemap.map", {25, 20});

    // Create entities
    Entity& player = EntityManager::instance()->addEntity("player", 2);
    player.addComponent<TransformComponent>(50, 50, 0, 0,
                                            32, 32, scale, scale);
    player.addComponent<SpriteComponent>("chopper", 2, 90, true, false);
    player.addComponent<KeyboardComponent>(SDLK_a, SDLK_d, SDLK_w, SDLK_s);
    player.addComponent<ColliderComponent>("player", 50, 50, 32*scale, 32*scale, "colliderBox");

    Entity& radar = EntityManager::instance()->addEntity("radar", 3);
    radar.addComponent<TransformComponent>(mainWindow->width()-64, 0, 0, 0,
                                            64, 64, 1, 1);
    radar.addComponent<SpriteComponent>("radar", 8, 90, false, true);

    Entity& tank = EntityManager::instance()->addEntity("tank", 2);
    tank.addComponent<TransformComponent>(100, 400, 0, 0,
                                            32, 32, scale, scale);
    tank.addComponent<SpriteComponent>("tank");
    tank.addComponent<ColliderComponent>("enemy", 0, 300, 32*scale, 32*scale, "colliderBox");

    Entity& bullet = EntityManager::instance()->addEntity("bullet", 2);
    bullet.addComponent<TransformComponent>(100+16, 400+16, 0, 0,
                                            4, 4, scale, scale);
    bullet.addComponent<SpriteComponent>("bullet");
    bullet.addComponent<ColliderComponent>("bullet", 100+16, 400+16, 4*scale, 4*scale, "colliderBox");
    bullet.addComponent<ProjectileEmmiterComponent>(50, 270, 200, true);

    SDL_Color whiteColor = {255, 255, 255, 255};
    ivec2 labelPos = {10, 10};
    Entity& label = EntityManager::instance()->addEntity("label", 3);
    label.addComponent<LabelComponent>(labelPos, "First level", "charriot", whiteColor);
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
    checkCollisions();
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

void Game::checkCollisions()
{
    string collisionTarget = EntityManager::instance()->checkEntityCollision("player");
    if(collisionTarget == "enemy"){
        cout<<"Collision with enemy\n";
    }else if(collisionTarget == "bullet"){
        stop();
    }
}

void Game::handleEvents()
{
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE){
        stop();
        return;
    }
    if(event.key.keysym.sym == SDLK_F1)
        EntityManager::instance()->tuggleColliderBox();
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
