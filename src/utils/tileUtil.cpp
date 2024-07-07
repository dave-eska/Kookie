#include "tileUtil.h"

#include <json/json.h>

#include "conversionUtil.h"
#include "fileUtil.h"

std::vector<std::unique_ptr<Tile>> loadLevelFromFile(std::string file_path, int& highet_z, Vector2& cvs_size, Vector2& str_pos){
    std::vector<std::unique_ptr<Tile>> vec;
    std::string text = readFile(file_path);
    Json::Value root;
    Json::Reader jsonreader;

    Vector2 canvas_size{0, 0};

    jsonreader.parse(text, root);

    Vector3 pos;
    int x = 0;
    int y = 0;
    int z = 0;

    std::string id;
    std::string destination;

    bool isReadingDestination;

    Vector2 starting_pos={root["x"].asFloat(), root["y"].asFloat()};

    for(const auto& layer : root["layers"]) {
        y = 0;
        x = 0;
        for (const auto& e : layer.asString()) {
            if((e == ' ' or e == '\n' or e == ',') && !id.empty()){
                int tile_id = std::stoi(id);
                Vector2 tile_pos = {starting_pos.x+x*TILE_SIZE, starting_pos.y+(y*TILE_SIZE)};
                if(isStrDigit(id)){
                    Tile tile = Tile(tile_id, {starting_pos.x+x*TILE_SIZE, starting_pos.y+(y*TILE_SIZE)}, z);
                    tile.setSlot(vec.size());
                    vec.push_back(std::make_unique<Tile>(tile));
                    id.clear();
                }

                if(e == ' '){
                    x++;
                    canvas_size.x = x;
                }else if(e == '\n' or ','){
                    y++;
                    canvas_size.y = y;
                    x = 0;
                }

            }else if (isdigit(e)) {
                id.push_back(e);
            }else if(isEnglishAlphabet(e)){
                destination.push_back(e);
            }
            canvas_size.y = y;
        }
        if(!id.empty()){
            Tile tile = Tile(std::stoi(id), {starting_pos.x+x*TILE_SIZE, starting_pos.y+(y*TILE_SIZE)}, z);
            tile.setSlot(vec.size());
            vec.push_back(std::make_unique<Tile>(tile));
            id.clear();
        }
        z++;
    }

    highet_z = z;
    cvs_size = {canvas_size.x+1, canvas_size.y+1};
    str_pos = starting_pos;

    return vec;
}
