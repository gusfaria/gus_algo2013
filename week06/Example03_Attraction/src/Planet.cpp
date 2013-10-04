//
//  Planet.cpp
//  Example03_Attraction
//
//  Created by Gustavo Faria on 01/10/13.
//
//

#include "Planet.h"


Planet::Planet() {
    mass = 1.0;
}

void Planet::applyForce(ofVec2f force){
    acc += (force / mass);
}

void Planet::update(){
    vel += acc;
    pos += vel;
    
    acc.set(0); //normalizer
}

ofVec2f Planet::attract( Planet p ){
    ofVec2f forceDir = pos - p.pos;
    float dist = forceDir.length();
    forceDir.normalize();
    
    float pullStrenght = (G * mass * p.mass) / (dist*dist);
    
    return forceDir * pullStrenght;
}



void Planet::draw(){
    ofCircle(pos, mass * 10);
}


