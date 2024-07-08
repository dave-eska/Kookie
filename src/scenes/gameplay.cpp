#include "gameplay.h"
#include "level.h"
#include "raylib.h"
#include "scene.h"
#include "tile.h"

#define CAM_SPEED (250)

void GameplayScene::Update(float dt){
    if(IsKeyPressed(KEY_ESCAPE))
        returnCode = 1;

    camera.target = {player->getBody().x + (player->getBody().width/2), player->getBody().y + (player->getBody().height/2)};

    level->Update(dt);
    player->Move(IsKeyDown(KEY_D)-IsKeyDown(KEY_A), IsKeyDown(KEY_S)-IsKeyDown(KEY_W), dt);
}

void GameplayScene::Draw(){
    BeginMode2D(camera);

    level->Draw();
    player->Draw();

    EndMode2D();
}

void GameplayScene::Unload(){
}

GameplayScene::GameplayScene() : Scene("Game", 0.5f){
    level = new Level("res/levels/test.json");
    player = new Player({
        .x = TILE_SIZE * 5,
        .y= TILE_SIZE * 2,
        .width = 18*9,
        .height = 35*9
    }, 450);

    camera.target = {player->getBody().x + (player->getBody().width/2), player->getBody().y + (player->getBody().height/2)};
    camera.offset = { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
}
