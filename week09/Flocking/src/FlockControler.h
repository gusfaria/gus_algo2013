//
//  FlockControler.h
//  Flocking
//
//  Created by Gustavo Faria on 22/10/13.
//
//

#pragma once

#include "ofMain.h"
#include "Bold.h"

class FlockControler {
    public:
    FlockControler();
    
    void addParticle (int numParticles = 1);
    
    void applyForces (float zoneRadius, float separateThresh=0.4, float alignThresh = 0.7 );
    
    void draw();
    void update();
    
    vector<Bold> boldList;
    
};