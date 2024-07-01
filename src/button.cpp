#include "button.h"
#include "raylib.h"

bool Button::onClick(int button){
    return onHover() && IsMouseButtonPressed(button);
}

bool Button::onHover(){
    return CheckCollisionPointRec(GetMousePosition(), body);
}

void Button::Draw(){
    DrawTextureEx(texture, onHover() ? hoverPos : drawPos, 0, onHover() ? hoverScale : scale, WHITE);
}

Button::Button(){
}

Button::Button(const char* texturePath, Vector2 pos, float scale) : scale{scale}{
    texture = LoadTexture(texturePath);
    body = {pos.x, pos.y, (float)texture.width*scale, (float)texture.height*scale};

    drawPos = {body.x, body.y};

    hoverScale = scale + 1.25f;
    hoverPos.x = pos.x - ((body.width*1.25 - body.width)/4);
    hoverPos.y = pos.y - ((body.height*1.25 - body.height)/4);
}
