//
//  Particles.h
//  ofApp
//
//  Created by Gustavo Faria on 02/12/13.
//
//

#pragma once
#include "ofMain.h"

class Particles{
public:
    Particles();
    void draw();
    void update();
    
    void addForce(ofVec2f force);
    void addRepulsionForce(float px, float py, float radius, float strength);
    void addAttractionForce(float px, float py, float radius, float strength);
    
    float friction;
    
    ofVec2f pos, vel, acc;

    
};
