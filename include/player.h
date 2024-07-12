#pragma once

#include <map>
#include <string>
#include <vector>

#include <raylib.h>

#include <box2d/b2_body.h>

#include "animation.h"
#include "box2d/b2_fixture.h"
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_world.h"

#define DIRECTION_UP 1
#define DIRECTION_DOWN 2
#define DIRECTION_LEFT 3
#define DIRECTION_RIGHT 4

static std::map<int, std::string> EnchantToStringMap = {
    { DIRECTION_RIGHT, "DIRECTION_RIGHT" },
    { DIRECTION_LEFT, "DIRECTION_LEFT" },
    { DIRECTION_UP, "DIRECTION_UP" },
    { DIRECTION_DOWN, "DIRECTION_DOWN" }
};

class Player{
private:
    Rectangle body;

    Texture2D texture;
    std::vector<SpriteAnimation> animations;

    int current_animation;
    int direction;

    b2Body* kinematicBody;
    b2PolygonShape boxShape;
    b2FixtureDef fixtureDef;

    int speed;

    static constexpr float PIXELS_PER_METER = 50.0f;


public:
    Rectangle getBody(){ return body; }
    Vector2 getPos(){ return {body.x, body.y}; }

    std::string getDirection();

    void Move(float dt);
    void Animate();

    Player(const char* texture_path, Vector2 pos, int speed,
           b2World& world);
};
