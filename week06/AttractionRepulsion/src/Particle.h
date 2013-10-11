//
//  Particle.h
//  AttractionRepulsion
//
//  Created by Gustavo Faria on 04/10/13.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    Particle();
    void draw();
    void update();
    
    void addForce(ofVec2f force);
    void addAttraction(float px, float py, float radius, float strength);
    void addRepulsion(float px, float py, float radius, float strength);
    
    
    ofVec2f pos, vel, acc;

    float friction;
    float size;    
};

