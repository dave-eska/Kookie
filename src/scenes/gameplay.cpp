#include "gameplay.h"

#include "level.h"
#include "raylib.h"
#include "scene.h"
#include "tile.h"
#include <iostream>

#define CAM_SPEED (250)

void GameplayScene::Update(float dt){
    if(IsKeyPressed(KEY_ESCAPE))
        returnCode = 1;

    camera.target = {player->getBody().x + (player->getBody().width/2), player->getBody().y + (player->getBody().height/2)};

    level->Update(dt);

    player->Move(dt);
}

void GameplayScene::Draw(){
    BeginMode2D(camera);

    level->Draw();
    player->Animate();

    EndMode2D();

    DrawText(player->getDirection().c_str(), 30, GetScreenHeight()-30, 20, BLACK);
}

void GameplayScene::Unload(){
}

GameplayScene::GameplayScene() : Scene("Game", 0.5f){
    level = new Level("res/levels/test.json");

    std::cout<<level->b2world->GetBodyCount()<<std::endl;

    player = new Player("res/img/player_atlas.png", {TILE_SIZE*5, TILE_SIZE*3}, 750, *level->b2world);

    std::cout<<level->b2world->GetBodyCount()<<std::endl;

    camera.target = {player->getBody().x + (player->getBody().width/2), player->getBody().y + (player->getBody().height/2)};
    camera.offset = { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
}
