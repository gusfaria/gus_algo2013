//
//  Particle.cpp
//  Example02_Forces
//
//  Created by Gustavo Faria on 01/10/13.
//
//

#include "Particle.h"


Particle :: Particle(){
    mass = 1.0f;
    pos = ofGetWindowSize() / 2;
    
    color.setHsb(ofRandom(255), 200, 250);
}

Particle :: Particle( ofVec2f position ){
    mass = 1.0f;
    pos = position;
}

void Particle :: applyForce( ofVec2f force ){
    acc += ( force / mass );
}


void Particle :: update(){
    vel += acc;
    pos += vel;
    
    if (pos.x < 0 || pos.x > ofGetWindowWidth() ) {
        vel.x = - vel.x;
    }
    if (pos.y < 0 || pos.y > ofGetWindowHeight() ) {
        vel.y = - vel.y;
    }
    
    acc.set(0); // normalize... set the acceleration to zero //acc is just the initial push
}

void Particle :: draw(){
    ofSetColor(color);
    ofCircle ( pos, mass*10.0 );
}