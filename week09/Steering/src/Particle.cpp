//
//  Particle.cpp
//  Forces
//
//  Created by Charlie Whitney on 9/30/13.
//
//

#include "Particle.h"

Particle::Particle() {

    pos = ofGetWindowSize() / 2.0;
    maxSpeed = 10.0;
    maxForce = 0.4;
}

void Particle::applyForce(ofVec2f force){
    accel += force;
}

void Particle::update(){
    vel += accel;
    pos += vel;
    
    accel.set(0);
}

void Particle::seek(ofVec2f dest){
    ofVec2f desired = dest - pos;
    
    desired.normalize();
    desired *= maxSpeed;
    ofVec2f steer = desired - vel;
    
    steer.limit ( maxSpeed );
    applyForce( steer );
    
}

void  Particle::addRepulsionForce(const ofVec2f &dest){
//    ofVec2f diff = pos - dist;
//    float strength = 1 - (diff.length)
    
}

void Particle::draw() {
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();{
        ofTranslate(pos);
        float rotAmt = atan2(vel.y, vel.x);
        ofRotate(ofRadToDeg(rotAmt));
        ofRect(0, 0, 40, 10);
    }ofPopMatrix();
    
    
    
}

