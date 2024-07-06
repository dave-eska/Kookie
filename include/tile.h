#pragma once

#include "animation.h"
#include <string>

#include <raylib.h>

#define TILE_SIZE (96)

class Tile{
private:
    std::string name;
    std::string type;
    int id;

    Rectangle body;
    int z_level;

    bool hasCollision;

    Texture2D texture;
    SpriteAnimation animation;
    bool animationOnDefault;
    bool isRunningAnimation;

public:
    bool hasAnimation();

    void Update();
    void Draw();

    Tile();
    Tile(int id, Vector2 pos, int z_level);
};
