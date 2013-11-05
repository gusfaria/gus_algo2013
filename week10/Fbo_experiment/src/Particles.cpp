//
//  Particles.cpp
//  Fbo_experiment
//
//  Created by Gustavo Faria on 01/11/13.
//
//

#include "Particles.h"


Particles::Particles(){
    setParams(0,0,0,0, color);
    damping.set(0.01,0.01);
    size = 100;
}

void Particles:: setParams(float px, float py, float vx, float vy, ofColor _color){
    pos.set(px,py);
    vel.set(vx,vy);
    color = _color;
}

void Particles:: addForce(ofVec2f force){
    frc += force;
}

void Particles::addRepulsionForce(float px, float py, float radius, float strength){
    
    ofVec2f posOfForce;
    posOfForce.set(px,py);
    
    ofVec2f diff = pos - posOfForce;
    
    if (diff.length() < radius) {
        float pct = 1 - (diff.length() / radius);
        diff.normalize();
        
        frc.x += diff.x * pct * strength;
        frc.y += diff.y * pct * strength;
    }
    
}


void Particles::addAttractionForce(float px, float py, float radius, float strength){
    
    ofVec2f posOfForce;
    posOfForce.set(px,py);
    
    ofVec2f diff = pos - posOfForce;
    
    if (diff.length() < radius) {
        float pct = 1 - (diff.length() / radius);
        diff.normalize();
        
        frc.x -= diff.x * pct * strength * 0.05;
        frc.y -= diff.y * pct * strength * 0.05;
        
    }
    
}


void Particles:: update(){
    vel += frc;
    pos += vel;
}


void Particles:: draw(){
    ofSetColor(color);
    ofCircle( pos , size );
}

