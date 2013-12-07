//
//  Particle.cpp
//  Example04_Attraction
//
//  Created by Gustavo Faria on 01/10/13.
//
//

#include "Particle.h"


Particle::Particle(){
    
    ofSetColor(color);
    color.setHsb(100, ofRandom(200), 255);
    friction = ofRandom(0.8,1.5);
    
    
    
    
}

void Particle::update(){
    vel += acc * sin(ofGetElapsedTimef() * 5);
    vel += acc * 5;
    pos += vel;
    
    vel *= friction;
    
    acc.set(0); //normalizer
    
    

}

void Particle::draw(){
    ofSetColor(color);
    ofCircle(pos, size);
}


void Particle::addForce( ofVec2f force ){
    acc += force;
}

void Particle::addRepulsionForce(float px, float py, float radius, float strength){
    
    ofVec2f posOfForce;
    posOfForce.set(px,py);
    
    ofVec2f diff = pos - posOfForce;
    
    if (diff.length() < radius) {
        float pct = 1 - (diff.length() / radius);
        diff.normalize();
        
        acc.x += diff.x * pct * strength;
        acc.y += diff.y * pct * strength;
        size = (acc.x * 10)+1;
//        size = 3;
    }
    
}


void Particle::addAttractionForce(float px, float py, float radius, float strength){
    
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