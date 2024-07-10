#include "gameplay.h"

#include "level.h"
#include "scene.h"

#define CAM_SPEED (250)

void GameplayScene::Update(float dt){
    if(IsKeyPressed(KEY_ESCAPE))
        returnCode = 1;

    //camera.target = {player->getBody().x + (player->getBody().width/2), player->getBody().y + (player->getBody().height/2)};

    level->Update(dt);

    int ix, iy;
    ix = IsKeyDown(KEY_D)-IsKeyDown(KEY_A);
    iy = IsKeyDown(KEY_S)-IsKeyDown(KEY_W);
}

void GameplayScene::Draw(){
    BeginMode2D(camera);

    level->Draw();

    EndMode2D();
}

void GameplayScene::Unload(){
}

GameplayScene::GameplayScene() : Scene("Game", 0.5f){
    level = new Level("res/levels/test.json");

    //camera.target = {player->getBody().x + (player->getBody().width/2), player->getBody().y + (player->getBody().height/2)};
    camera.offset = { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
}
