#pragma once

#include <raylib.h>

#include "level.h"
#include "player.h"
#include "scene.h"

class GameplayScene : public Scene{
private:
    Level* level;
    Player* player;
public:
    void Update(float dt) override;
    void Draw() override;

    void Unload() override;

    GameplayScene();
};
