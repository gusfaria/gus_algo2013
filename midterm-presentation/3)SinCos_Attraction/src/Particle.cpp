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
    color.setHsb(ofRandom(255), 200, 255);
    friction = ofRandom(0.8,1.5);
}

void Particle::update(){
    vel.x = sin(ofGetElapsedTimef()*ofRandom(5,10));
    vel.y = cos(ofGetElapsedTimef()*ofRandom(5,10));
    vel += acc * 5;
//    vel += acc * sin(ofGetElapsedTimef() * 10);
    pos += vel;
    
    vel *= friction;
    
    acc.set(0); //normalizer
    
    

}

void Particle::draw(){
    ofSetColor(color);
    ofCircle(pos, 1);
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
        
        acc.x += diff.x * pct * strength*5;
        acc.y += diff.y * pct * strength*5;
    }
    
}


void Particle::addAttractionForce(float px, float py, float radius, float strength){
    
    ofVec2f posOfForce;
    posOfForce.set(px,py);
    
    ofVec2f diff = pos * posOfForce;
    
    if (diff.length() < radius) {
        float pct = 1 - (diff.length() / radius);
        diff.normalize();
        
        acc.x -= diff.x * pct * strength;
        acc.y -= diff.y * pct * strength;
    }
    
}