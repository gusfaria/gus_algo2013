//
//  Particle.h
//  Steering2
//
//  Created by Gustavo Faria on 27/10/13.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    
    Particle();
    void update();
    void draw();
    
    void setParam(ofVec2f _pos, ofVec2f _vel);
    void addForce(ofVec2f force);
    void seek(ofVec2f dest);
    
    ofVec2f damping;
    ofVec2f vel;
    ofVec2f pos;
    ofVec2f acc;
    ofVec2f lastPos;
};
