#include <raylib.h>

#include "scene.h"

#include "gameplay.h"
#include "mainmenu.h"

static MainMenuScene *mainmenu;
static GameplayScene *gameplay;

void changeScene(Scenes &currentScene, Scenes newScene);

int main(){

    InitWindow(GetScreenWidth(), GetScreenHeight(), "Kookies");
    SetExitKey(0);

    Scenes currentScene;
    float dt = 0.0f;

    changeScene(currentScene, Scenes::MainMenu);

    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

    while(!WindowShouldClose()){
        dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(GRAY);

        switch(currentScene){
            case Scenes::MainMenu:{
                mainmenu->Update(dt);
                if(mainmenu->getReturnCode() == 1) changeScene(currentScene, Scenes::GamePlay);
                if(mainmenu->getReturnCode() == 2) changeScene(currentScene, Scenes::LevelEditor);
                if(mainmenu->getReturnCode() == 3) changeScene(currentScene, Scenes::Option);
                mainmenu->Draw();
                break;
            }
            case Scenes::GamePlay:{
                gameplay->Update(dt);
                if(gameplay->getReturnCode() == 1) changeScene(currentScene, Scenes::MainMenu);
                gameplay->Draw();
                break;
            }
            default:
                break;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void changeScene(Scenes &currentScene, Scenes newScene){
    switch(currentScene){
        case Scenes::MainMenu:
            mainmenu->resetReturnCode();
            mainmenu->Unload();
            break;
        case Scenes::GamePlay:
            gameplay->resetReturnCode();
            gameplay->Unload();
            break;
        default:
            break;
    }

    switch(newScene){
        case Scenes::MainMenu:
            mainmenu = new MainMenuScene();
            break;
        case Scenes::GamePlay:
            gameplay = new GameplayScene();
            break;
        case Scenes::Option:
            //option = OptionScene();
            break;
        default:
            break;
    }
    currentScene = newScene;
}
