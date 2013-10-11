//
//  Particle.cpp
//  AttractionRepulsion
//
//  Created by Gustavo Faria on 04/10/13.
//
//

#include "Particle.h"


Particle::Particle(){
    friction = ofRandom(0.8,0.95);
    size = 3;
}

void Particle::update(){
    vel += acc;
    pos += pos;
    vel+= friction;
    acc.set(0);
}

void Particle::draw(){
    ofCircle(pos, size);
}

void Particle::addForce(ofVec2f force){
    acc+=force;
    
}

void Particle::addAttraction(float px, float py, float radius, float strength) {
    
    
}

void Particle::addRepulsion(float px, float py, float radius, float strength){
    
    
}