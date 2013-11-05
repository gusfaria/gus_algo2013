//
//  Particles.h
//  Fbo_experiment
//
//  Created by Gustavo Faria on 01/11/13.
//
//

#pragma once
#include "ofMain.h"

class Particles{
public:
    
    Particles();
    void setParams(float px, float py, float vx, float vy, ofColor _color);
    void addForce(ofVec2f force);
    void addRepulsionForce(float px, float py, float radius, float strength);
    void addAttractionForce(float px, float py, float radius, float strength);

    
    void draw();
    void update();
    
    ofVec2f damping;
    ofVec2f pos, vel, frc;    

    
    ofColor color;
    float size;
};