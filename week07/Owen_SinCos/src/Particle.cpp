//
//  Particle.cpp
//  week5_trig
//
//  Created by Owen Herterich on 9/28/13.
//
//

#include "Particle.h"

Particle::Particle( float _sin, float _cos, float _velX, float _size ) {
    pos.set(0, 0);
    sinChange = _sin;
    cosChange = _cos;
    amp = _velX;
    
    life = 500.0;
    age = 0.0;
    
    vel.y = sin( sinChange ) + cos ( cosChange );
    size = _size;
    theta = 100.0;
    color.setHsb(ofRandom(100), 100 , 250);

}

void Particle::update( float _sin, float _cos, float _velX, float _size) {
    sinChange = _sin;
    cosChange = _cos;
    amp = _velX;
    
    vel.x = cos( cosChange * theta ) * amp;
    vel.y = sin( sinChange * theta ) * amp;
    pos += vel;
    size = _size;
    theta += 0.01;
    age++;
}

void Particle::draw() {
    for (int i = 1; i < 6; i++) {
        for (int k = 1; k < 5; k++) {
            ofPushMatrix();{
                ofTranslate((ofGetWindowWidth()/2 * i)/2-190,(ofGetWindowHeight()/2 * k)/2-170);
                ofSetColor(color,90);
                ofCircle(pos, size);
    //                ofNoFill();
    //                ofRect(pos,size,size);
            }ofPopMatrix();
        }
    }
    
}

bool Particle::kill() {
    if (age >= life) {
        return true;
    }
    else return false;
}