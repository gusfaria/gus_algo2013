//
//  Particles.cpp
//  ofApp
//
//  Created by Gustavo Faria on 02/12/13.
//
//

#include "Particles.h"


Particles::Particles(){
    friction = ofRandom(0.8,1.5);
}

void Particles::update(){
    vel += acc ;
    pos += vel;
    
    vel *= friction;
    acc.set(0); //normalizer
}

void Particles::draw(){
//    ofSetColor(ofColor::magenta);
    ofCircle(pos, 4);
}

void Particles::addForce(ofVec2f force){
    acc += force;
}

void Particles::addRepulsionForce(float px, float py, float radius, float strength){
    ofVec2f posOfForce;
    posOfForce.set(px,py);
    
    ofVec2f diff = pos - posOfForce;
    
    if (diff.length() < radius) {
        float pct = 1 - (diff.length() / radius);
        diff.normalize();
        acc.x += diff.x * pct * strength;
        acc.y += diff.y * pct * strength;
    }
    
}

void Particles::addAttractionForce(float px, float py, float radius, float strength){
    ofVec2f posOfForce;
    posOfForce.set(px,py);
    
    ofVec2f diff = pos - posOfForce;
    
    if (diff.length() < radius) {
        float pct = 1 - (diff.length() / radius);
        diff.normalize();
        
        acc.x -= diff.x * pct * strength;
        acc.y -= diff.y * pct * strength;
        
    }
    
}