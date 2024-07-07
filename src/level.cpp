#include "level.h"

#include <iostream>
#include <ostream>

#include "tileUtil.h"

void Level::loadPath(std::string path){
    tiles = loadLevelFromFile(path, total_layers, size, starting_pos);
    name = path;

    std::cout<<"Successly loaded level '"<<path<<"'."<<std::endl;
}

void Level::Update(float dt){
    for(auto& tile : tiles){
        tile->Update();
    }
}

void Level::Draw(){
    for(auto& tile : tiles){
        tile->Draw();
    }
}

Level::Level(){
}

Level::Level(std::string path){
    tiles = loadLevelFromFile(path, total_layers, size, starting_pos);
    name = path;

    std::cout<<"Successly loaded level '"<<path<<"'."<<std::endl;
}
