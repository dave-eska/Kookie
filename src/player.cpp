#include "player.h"
#include "raylib.h"

void Player::Move(int inputX, int inputY, float dt){
    body.x += (inputX * speed) * dt;
    body.y += (inputY * speed) * dt;
}

void Player::Draw(){
    DrawRectangleRec(body, WHITE);
}

Player::Player(Rectangle body, int speed) : body{body}, speed{speed}{
}
