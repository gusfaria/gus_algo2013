//
//  Particle.cpp
//  Forces
//
//  Created by Charlie Whitney on 9/30/13.
//
//

#include "Particle.h"

Particle::Particle() {
    mass = 1.0;
}

void Particle::applyForce(ofVec2f force){
    accel += (force / mass);
}

void Particle::update( float dt ){
    vel += accel;
    pos += ( vel * dt );
    
    vel*= 1;
    
//    accel.set(0);
    
    if(pos.x < 0 || pos.x > ofGetWindowWidth()){
        vel.x *= -1;
    }
    
    if(pos.y < 0 || pos.y > ofGetWindowHeight()){
        vel.y *= -1;
    }
    
}

void Particle::draw() {
    ofSetColor(ofColor::magenta);
    ofCircle( pos, 4 );
}