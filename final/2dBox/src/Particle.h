//
//  Particle.h
//
//  Created by Gustavo Faria on 06/12/13.
//
//

#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class Particle{
public:
    Particle();
    
    void update();
    void draw();
    
    void setParams(float px, float py, float vx, float vy);
//    void addForce(ofVec2f force);
//    void addDampingForce();
//    void resetForces();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    ofVec2f damping;
    
    ofVec2f pSize;
    ofColor color;
};

