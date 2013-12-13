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
    
    float friction;
    
    ofVec2f pos, vel, acc;
    ofImage pizza;

    
};
