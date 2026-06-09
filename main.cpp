#include "projectile.h"
#include "projectile.cpp"
#include <iostream>

using namespace std;

int main(){

    launch(45.0f,25.0f); //11.1 degrees, 25 m/s, i think
    while(isActive()){
        update(0.1f); //seconds
        cout << "x: " << getX() << ", y: " << getY() << endl;
    };
}

