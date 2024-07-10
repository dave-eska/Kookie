#pragma once

#include "animation.h"
#include "raylib.h"
class Player{
private:
    Rectangle body;
    Texture2D texture;
    SpriteAnimation animation;

    int speed;
public:

    void Move(float dt);
    void Draw();

    Player();
};
