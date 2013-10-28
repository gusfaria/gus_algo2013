//
//  Particle.cpp
//  Steering2
//
//  Created by Gustavo Faria on 27/10/13.
//
//

#include "Particle.h"


Particle::Particle(){
    
    damping.set(0.05);
    
}

void Particle::setParam(ofVec2f _pos, ofVec2f _vel){
 
    pos = _pos;
    vel = _vel;
    
    lastPos.set( pos );
}


void Particle::addForce(ofVec2f force){
    acc += force;
}

void Particle::seek( ofVec2f dest ){
    //what is happening here????
    
    float maxSpeed = 10.0;
    float maxForce = 0.4;
    float slowDownRadius = 200;
    
    ofVec2f desired = dest - pos;
    cout << "desired :: " << desired << endl;
    
    if(dest.length() < slowDownRadius){
        float newMag = ofMap( desired.length(), 0, slowDownRadius, 0, maxSpeed);
        desired.normalize(); // why I need normalize? and when to use it?
        desired *= newMag;
    } else {
        desired.normalize(); // why I need normalize? and when to use it?
        desired *= maxSpeed;
    }
    
    
    ofVec2f steer = desired - vel;
    cout << "steer :: " <<  steer << endl;
    
    
    addForce(steer);
}

void Particle::update(){
    vel += acc;
    pos += vel;
    
    vel *= 0.97;
    acc *= 0;
    
    lastPos.set ( pos );
}


void Particle::draw(){
//    ofSetColor(0);
//    ofNoFill();
//    ofCircle(pos, 10);
//    ofFill();
//    ofSetColor(ofColor::magenta);
//    ofCircle(pos, 10);
    
    
    //what is happening here?
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();{
        ofTranslate( pos );
        float rotAmt = atan2( vel.y, vel.x );
        ofRotate( ofRadToDeg(rotAmt) + 90 );
        ofSetColor(ofColor :: magenta);
        ofRect(0,0, 20, 40);
    }ofPopMatrix();
    
    
    
}