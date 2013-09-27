

#pragma once

#include "ofMain.h"


class Particle{
public:
    Particle();
    void update();
    void draw();
    
    // my voids
    void setParams(float px, float py, float vx, float vy);
    void addForce( ofVec2f force);
    void addDampingForce();
    void resetForces();
    
    ofVec2f pos, vel;
    ofVec2f frc;
    ofVec2f damping;
};

