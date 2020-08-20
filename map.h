#ifndef MAP_H
#define MAP_H

#include <string>
#include "utils.h"
using namespace std;

class Map
{
public:
    Map(string textureId, int scale, int tileSize);
    ~Map();

    void loadFrom(string filePath, iSize mapSize);
    void addTile(iPoint srcPos, iPoint mapPos);

private:
    int tileCount = 0;
    string textureId;
    int scale;
    int tileSize;
};

#endif // MAP_H
