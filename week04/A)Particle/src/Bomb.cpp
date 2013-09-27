//
//  Bomb.cpp
//  Particle
//
//  Created by Gustavo Faria on 27/09/13.
//
//

#include "Bomb.h"


Bomb::Bomb(){
    pos.x = ofRandom(ofGetWindowWidth());
    pos.y = ofGetWindowHeight();
    vel.y = ofRandom(-20.0, -8.0);
    initVel = vel.y;
    color.setHsb(ofRandom(255), 200, 200);
    size = ofRandom(2.0, 5.0);
}

void Bomb::update(float velX){
    
    vel.y *= 0.98;
//    vel.x = (sin(ofGetElapsedTimef()*0.5));
    vel.x = velX;
    
    pos += vel;
}

void Bomb::draw(){
    ofSetColor(color);
    ofCircle(pos, size);
}

bool Bomb::bExploded(){
    if (abs(vel.y) <= 2.0) {
        return true;
    }
    else {
        return false;
    }
}