#include "gameplay.h"
#include "raylib.h"

void GameplayScene::Update(float dt){
    if(IsKeyPressed(KEY_ESCAPE))
        returnCode = 1;
}

void GameplayScene::Draw(){
    tile.Draw();
}

void GameplayScene::Unload(){
    tile.Draw();
}

GameplayScene::GameplayScene(){
    tile = Tile(2, {0, 0}, 0);
}
