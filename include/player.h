#pragma once

#include "raylib.h"
class Player{
private:
    Rectangle body;
    int speed;

public:
    Rectangle getBody(){ return body; }
    Vector2 getPos(){ return {body.x, body.y}; }

    void Move(int dx, int dy, float dt);
    void Draw();

    Player(Rectangle body, int speed);
};
