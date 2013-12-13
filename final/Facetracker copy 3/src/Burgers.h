//
//  Burgers.h
//  ofApp
//
//  Created by Gustavo Faria on 13/12/13.
//
//

#pragma once
#include "ofMain.h"

class Burger{
public:
    Burger();
    void draw();
    void update();
    
    void addForce(ofVec2f force);
    
    float friction;
    
    ofVec2f pos, vel, acc;
    ofImage burger;
    
};