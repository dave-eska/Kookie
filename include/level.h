#pragma once

#include <string>
#include <vector>
#include <memory>

#include <raylib.h>

#include "tile.h"

class Level{
private:
    std::vector<std::unique_ptr<Tile>> tiles;
    Vector2 starting_pos;
    Vector2 size;
    int total_layers;

    std::string name;
public:
    void loadPath(std::string path);

    void Update(float dt);
    void Draw();

    Level();
    Level(std::string path);

};
