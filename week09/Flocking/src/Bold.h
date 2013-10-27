//
//  Bold.h
//  Flocking
//
//  Created by Gustavo Faria on 22/10/13.
//
//

#pragma once
#include "ofMain.h"

//by the way,,,, it should be BOiD and not BOLD
class Bold {
public:
    Bold();
    
    void applyForce( ofVec3f force );
    void pullToCenter( ofVec3f center );
    
    void update();
    void draw();
    
    float damping;
    ofVec3f pos, vel, acc;
    
    
    
};


