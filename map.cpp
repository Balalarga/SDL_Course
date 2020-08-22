#include "map.h"
#include <fstream>
#include <iostream>
#include "game.h"
#include "entitymanager.h"
#include "Components/tilecomponent.h"

Map::Map(string textureId, int scale, int tileSize):
    textureId(textureId),
    scale(scale),
    tileSize(tileSize)
{
}

Map::~Map()
{
}

void Map::loadFrom(string filePath, ivec2 mapSize)
{
    ifstream file(filePath);
    if(!file){
        cout<<"No "<<filePath<<" founded\n";
        return;
    }
    char ch;
    ivec2 srcPos;
    for(int y = 0; y < mapSize.y; y++){
        for(int x = 0; x < mapSize.x; x++){
            file.get(ch);
            srcPos.y = atoi(&ch)*tileSize;
            file.get(ch);
            srcPos.x = atoi(&ch)*tileSize;
            addTile(srcPos, {x*scale*tileSize, y*scale*tileSize});
            file.ignore();
        }
    }
    file.close();
}

void Map::addTile(ivec2 srcPos, ivec2 mapPos)
{
    Entity& tile = EntityManager::instance()->addEntity("Tile"+to_string(tileCount++), 0);
    tile.addComponent<TileComponent>(textureId, srcPos, mapPos, tileSize, scale);
}
