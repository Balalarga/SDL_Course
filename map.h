#ifndef MAP_H
#define MAP_H

#include <string>
#include <glm/glm.hpp>
using namespace glm;

using namespace std;

class Map
{
public:
    Map(string textureId, int scale, int tileSize);
    ~Map();

    void loadFrom(string filePath, ivec2 mapSize);
    void addTile(ivec2 srcPos, ivec2 mapPos);

private:
    int tileCount = 0;
    string textureId;
    int scale;
    int tileSize;
};

#endif // MAP_H
