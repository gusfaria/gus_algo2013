//
//  Particle.h
//  SingleParticle
//
//  Created by Charlie Whitney on 9/23/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
  public:
    Particle(ofPoint _pos);
    
    void update();
    void draw();
    
    vector <ofImage> cards;

    ofVec2f pos;
    ofVec2f vel;
    float acc;
};