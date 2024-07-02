#include <raylib.h>

#include "scene.h"

#include "gameplay.h"
#include "mainmenu.h"

int main(){

    InitWindow(GetScreenWidth(), GetScreenHeight(), "Kookies");
    SetExitKey(0);

    MainMenuScene mainmenu = MainMenuScene();
    GameplayScene gameplay = GameplayScene();

    Scenes currentScene = Scenes::MainMenu;
    float dt = 0.0f;

    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

    while(!WindowShouldClose()){
        dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(GRAY);

        switch(currentScene){
            case Scenes::MainMenu:{
                mainmenu.Update(dt);
                if(mainmenu.getReturnCode() == 1) currentScene = Scenes::GamePlay;
                if(mainmenu.getReturnCode() == 2) currentScene = Scenes::LevelEditor;
                if(mainmenu.getReturnCode() == 3) currentScene = Scenes::Option;
                mainmenu.Draw();
                break;
            }
            case Scenes::GamePlay:{
                gameplay.Update(dt);
                gameplay.Draw();
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
