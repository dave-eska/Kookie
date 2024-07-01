#include "scene.h"
#include "raylib.h"

void Scene::Update(float dt){
}

void Scene::Draw(){
}

Scene::Scene(){
}

Scene::Scene(std::string title, int cameraZoom) : title{title}{
    is_debugging = false;
    is_typing = false;

    SetWindowTitle(title.c_str());

    camera = { 0 };
    camera.zoom = cameraZoom;
}
