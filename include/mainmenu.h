#pragma once

#include "raylib.h"
#include "scene.h"

#include "button.h"

class MainMenuScene : public Scene{
private:
    Texture2D mainmenu_texture;

    Button startgameButton;
    Button leveleditorButton;
    Button optionButton;
public:
    void Update(float dt) override;
    void Draw() override;

    MainMenuScene();
};
