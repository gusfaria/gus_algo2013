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
    vel.y = ofRandom(-25.0, -10.0);
    initVel = vel.y;
    color.setHsb(ofRandom(255), 255, 255);
    size = ofRandom(5.0, 10.0);
}

void Bomb::update(){
    pos += vel;
    vel *= 0.96;
}

void Bomb::draw(){
    ofSetColor(color);
    ofCircle(pos, size);
}

bool Bomb::bExploded(){
    if (abs(vel.y) <= 3.0) {
        return true;
    }
    else {
        return false;
    }
}