#include "mainmenu.h"
#include "raylib.h"
#include "scene.h"

void MainMenuScene::Update(float dt){
    if(startgameButton.onClick(MOUSE_LEFT_BUTTON))
        returnCode = 1;
}

void MainMenuScene::Draw(){
    DrawTextureEx(mainmenu_texture, {0, 0}, 0, 10, WHITE);

    startgameButton.Draw();
    leveleditorButton.Draw();
    optionButton.Draw();
}

void MainMenuScene::Unload(){
}

MainMenuScene::MainMenuScene() : Scene("Main Menu", 0){
    mainmenu_texture = LoadTexture("res/img/main_menu.png");

    startgameButton = Button("res/img/start_game_button.png", {110, 370}, 10);
    leveleditorButton = Button("res/img/level_editor_button.png", {110, 590}, 10);
    optionButton = Button("res/img/OptionButton.png", {1159, 824}, 5);
}
