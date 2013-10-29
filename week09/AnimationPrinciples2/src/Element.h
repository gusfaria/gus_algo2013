//
//  Element.h
//  AnimationPrinciples
//
//  Created by Gustavo Faria on 28/10/13.
//
//

#pragma once
#include "ofMain.h"


class Element{
public:
    Element();
    void setup();
    void update();
    void draw();
    void reset();
    
    ofColor color;
    ofVec2f pos, vel;
    float acc;
    
    float rectSize, increment;
    
};