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
    void setup(ofVec2f _Pos, float velMult, float hue);
    void update();
    void draw();
    bool bIsDied();

    ofVec2f pos;
    ofVec2f vel;
    ofVec2f acc;
    ofColor color;
    
    float size;
    float age;
    float life;
    
    
};



#endif /* defined(__Particle__Particle__) */
