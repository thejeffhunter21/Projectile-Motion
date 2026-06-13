#pragma once

#include <cmath>  // for cos(), sin(), M_PI

// your projectile state
struct Projectile {
    float x, y;
    float vx, vy;
    bool active;
};

// constants
const float grav = 9.8f;

// function declarations
extern "C" {
void launch(float angleDeg, float speed, float height);
void update(float dt);
float getX();
float getY();
bool isActive();
float getVx();
float getVy();
}