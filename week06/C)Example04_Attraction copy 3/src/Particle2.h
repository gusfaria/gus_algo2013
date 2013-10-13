//
//  Particle2.h
//  Example04_Attraction
//
//  Created by Gustavo Faria on 05/10/13.
//
//


#pragma once
#include "ofMain.h"


class Particle2{
public:
    Particle2();
    
    ofVec2f pos, vel, acc;
    
    void addForcePart2( ofVec2f force );
    void update();
    void draw();
    
    void addRepulsionForcePart2(float px, float py, float radius, float strengt);
    void addAttractionForcePart2(float px, float py, float radius, float strength);
    
    float frictionPart2;
    float sizePart2;
    ofColor colorPart2;
};