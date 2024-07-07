#pragma once

#include <raylib.h>

#include "level.h"
#include "scene.h"

class GameplayScene : public Scene{
private:
    Level* level;
public:
    void Update(float dt) override;
    void Draw() override;

    void Unload() override;

    GameplayScene();
};
