#include "projectile.h"
#define EMSCRIPTEN_KEEPALIVE __attribute__((used)) //used for git
#include <iostream>

Projectile proj; //Create projectile instance


extern "C" {
EMSCRIPTEN_KEEPALIVE
void launch(float angleDeg, float speed, float height) { //Convert radians to degrees so we can use sin/cos
    float angleRad = angleDeg * (M_PI / 180.0f);
    proj.x = 0;
    proj.y = height;
    proj.vx = speed * cos(angleRad); //speed along x axis
    proj.vy = speed * sin(angleRad); //speed along y axis
    proj.active = true; //let us know if it is in motion
}
EMSCRIPTEN_KEEPALIVE
void update(float dt){ //Update position of object
    if (!proj.active){
        return; //If not moving, end
    }

    //update position due to gravity over an infinitesmal time
    proj.vy -= grav * dt;
    proj.x += proj.vx * dt;
    proj.y += proj.vy * dt;
    
    if (proj.y <= 0){ //check if it is on the ground
        proj.y = 0; //stick to the ground for simulator
        proj.active = false; //setting this false allows for loop to know when to stop
        return;
    }  
}
EMSCRIPTEN_KEEPALIVE
float getX() { return proj.x; } //getters for position
EMSCRIPTEN_KEEPALIVE
float getY() { return proj.y; }
EMSCRIPTEN_KEEPALIVE
bool isActive() { return proj.active; } //getter for boolean
}
EMSCRIPTEN_KEEPALIVE
float getVx() { return proj.vx; }
EMSCRIPTEN_KEEPALIVE
float getVy() { return proj.vy; }