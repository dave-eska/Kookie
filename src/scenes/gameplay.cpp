#include "gameplay.h"
#include "raylib.h"

#include <iostream>

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
    std::cout<<"gameplay"<<std::endl;
    tile = Tile(1, {0, 0}, 0);
}
