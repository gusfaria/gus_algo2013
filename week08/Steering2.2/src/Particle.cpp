//
//  Particle.cpp
//  Steering2
//
//  Created by Gustavo Faria on 27/10/13.
//
//

#include "Particle.h"


Particle::Particle(){
    
    damping.set(0.01);
    
    maxSpeed = 10.0;
    maxForce = 0.4;
    slowDownRadius = 200.0;
    
}

void Particle::setParam(ofVec2f _pos, ofVec2f _vel){
 
    pos = _pos;
    vel = _vel;
    
    lastPos.set( pos );
}


void Particle::addForce(ofVec2f force){
    acc += force;
    acc.limit( 5.0 );
}

void Particle::seek( const ofVec2f &dest ){
    //what is happening here????
    

    
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

void Particle::addRepulsionForce (const ofVec2f &fromPos){
    ofVec2f diff = pos - fromPos;
    float strength = 1- (diff.length() / 200.0);
    addForce( diff.normalized() * (strength) );
}

void Particle::update(){
    vel += acc;
    pos += vel;
    
    vel *= 0.97;
    acc *= 0;
    
    lastPos.set ( pos );
}


void Particle::draw(){
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();{
        ofTranslate( pos );
        float rotAmt = atan2( vel.y, vel.x );
        ofRotate( ofRadToDeg(rotAmt) + 90 );
        ofRect(0,0, 20, 40);
    }ofPopMatrix();
    
}