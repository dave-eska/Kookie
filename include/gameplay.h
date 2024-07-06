#pragma once

#include <raylib.h>

#include "scene.h"
#include "tile.h"

class GameplayScene : public Scene{
private:
    Tile tile;
public:
    void Update(float dt) override;
    void Draw() override;

    void Unload() override;

    GameplayScene();
};
