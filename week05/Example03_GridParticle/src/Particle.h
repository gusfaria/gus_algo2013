//
//  Particle.h
//  Example03_GridParticle
//
//  Created by Gustavo Faria on 24/09/13.
//
//

#pragma once

#include "ofMain.h"

class Particle{
    
public:
    Particle ( ofVec2f position );
    void draw();
    
    ofVec2f pos;
    float radius;
    float grayValue;
    
};


