#pragma once

#include "raylib.h"
#include <string>

class Scene{
protected:
    std::string title;
    bool is_debugging;
    bool is_typing;

    Camera2D camera;

public:
    std::string getTitle(){return title;}

    virtual void Update(float dt)=0;
    virtual void Draw()=0;

    Scene();
    Scene(std::string title, int cameraZoom);

};

enum class Scenes{
    MainMenu
};
