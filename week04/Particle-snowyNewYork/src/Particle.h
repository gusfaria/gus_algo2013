//
//  Particle.h
//  Particle
//
//  Created by Gustavo Faria on 20/09/13.
//
//

#ifndef __Particle__Particle__
#define __Particle__Particle__

#include <iostream>
#include "ofMain.h"

class Particle{
public:
    Particle(){};
    void setup( ofVec2f rVel );
    void update();
    void draw();
    
    ofVec2f pos;
    ofVec2f vel;
    int age, lifespan;
    bool bIsDead;
    
    
};



#endif /* defined(__Particle__Particle__) */
