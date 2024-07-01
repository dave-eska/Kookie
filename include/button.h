#pragma once

#include <raylib.h>

class Button{
private:
    Texture2D texture;
    Rectangle body;

    float scale;
    Vector2 drawPos;

    float hoverScale;
    Vector2 hoverPos;
public:
    bool onClick(int button);
    bool onHover();

    void Draw();

    Button();
    Button(const char* texturePath, Vector2 pos, float scale);
};
