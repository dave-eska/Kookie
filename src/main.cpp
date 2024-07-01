#include "mainmenu.h"
#include <raylib.h>

int main(){

    InitWindow(GetScreenWidth(), GetScreenHeight(), "Kookies");
    SetExitKey(0);

    MainMenuScene mainmenu = MainMenuScene();

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
                mainmenu.Draw();
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
