//
//  Particle.h
//  GUI_Particles
//
//  Created by Gustavo Faria on 30/09/13.
//
//

#pragma once

#include "ofMain.h"

class Particle{
public:
    Particle(float particleSize, ofColor _color);
    
    void update();
    void draw();
    
    void setParams(float px, float py, float vx, float vy);
    void addForce(ofVec2f force);
    void addDampingForce();
    void resetForces();
    
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    ofVec2f damping;
    
    float pSize;
    ofImage bubble;
    bool bColor;
    ofColor color;
};
