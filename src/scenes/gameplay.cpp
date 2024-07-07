#include "gameplay.h"
#include "level.h"
#include "raylib.h"
#include "scene.h"

#define CAM_SPEED (250)

void GameplayScene::Update(float dt){
    if(IsKeyPressed(KEY_ESCAPE))
        returnCode = 1;

    if(IsKeyDown(KEY_W)) camera.target.y -= CAM_SPEED * dt;
    if(IsKeyDown(KEY_A)) camera.target.x -= CAM_SPEED * dt;
    if(IsKeyDown(KEY_S)) camera.target.y += CAM_SPEED * dt;
    if(IsKeyDown(KEY_D)) camera.target.x += CAM_SPEED * dt;

    level->Update(dt);
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
}
