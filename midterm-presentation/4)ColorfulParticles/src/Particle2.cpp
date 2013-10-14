//
//  Particle2.cpp
//  Example04_Attraction
//
//  Created by Gustavo Faria on 05/10/13.
//
//

#include "Particle2.h"



Particle2::Particle2(){
    
    ofSetColor(colorPart2);
    colorPart2.setHsb(250, ofRandom(200), 255);
//    colorPart2.set(255,0,0);
    frictionPart2 = ofRandom(0.6,1.2);
    
    
    
    
}

void Particle2::update(){
    vel += acc * sin(ofGetElapsedTimef() * 2);
    
    vel += acc;
    pos += vel;
    
    vel *= frictionPart2;
    
    acc.set(0); //normalizer
    
    
    
}

void Particle2::draw(){
    ofSetColor(colorPart2);
    ofCircle(pos, sizePart2);
}


void Particle2::addForcePart2( ofVec2f force ){
    acc += force*10;
}

void Particle2::addRepulsionForcePart2(float px, float py, float radius, float strength){
    
    ofVec2f posOfForce;
    posOfForce.set(px,py);
    
    ofVec2f diff = pos - posOfForce;
    
    if (diff.length() < radius) {
        float pct = 1 - (diff.length() / radius);
        diff.normalize();
        
        acc.x += diff.x * pct * strength;
        acc.y += diff.y * pct * strength;
        sizePart2 = (acc.x * 5)+1;
//        sizePart2 = 3;
    }
    
}


void Particle2::addAttractionForcePart2(float px, float py, float radius, float strength){
    
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