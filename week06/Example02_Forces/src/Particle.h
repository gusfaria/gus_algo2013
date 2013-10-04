//
//  Particle.h
//  Example02_Forces
//
//  Created by Gustavo Faria on 01/10/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    // c++ will know when to use one or the other!!
    // By default it will go with the first one!!
    Particle();
    Particle( ofVec2f position );

    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f acc;
    
    float mass;
    
    void applyForce ( ofVec2f force );
    void update();
    void draw();
    
    ofColor color;
    
};

