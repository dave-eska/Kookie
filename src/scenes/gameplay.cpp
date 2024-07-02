#include "gameplay.h"
#include "raylib.h"

void GameplayScene::Update(float dt){
    if(IsKeyDown(KEY_W)) player.y -= 250 * dt;
    if(IsKeyDown(KEY_A)) player.x -= 250 * dt;
    if(IsKeyDown(KEY_S)) player.y += 250 * dt;
    if(IsKeyDown(KEY_D)) player.x += 250 * dt;
}

void GameplayScene::Draw(){
    DrawRectangleRec(player, BLACK);
}

GameplayScene::GameplayScene(){
    player = {0, 0, 50, 50};
    camera.target = {player.x, player.y};
}
