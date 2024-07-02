#pragma once

#include <raylib.h>

#include "scene.h"

class GameplayScene : public Scene{
private:
    Rectangle player;
public:
    void Update(float dt) override;
    void Draw() override;

    GameplayScene();
};
