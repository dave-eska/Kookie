#pragma once

#include <vector>
#include <memory>

#include <raylib.h>

#include "tile.h"

std::vector<std::unique_ptr<Tile>> loadLevelFromFile(std::string file_path, int& highet_z, Vector2& cvs_size, Vector2& str_pos);
