//
//  Particle.cpp
//  Steering2
//
//  Created by Gustavo Faria on 27/10/13.
//
//

#include "Particle.h"


Particle::Particle(){
    setParam(ofVec2f(0,0), ofVec2f(0,0));
    damping.set(0.01);
    
    maxSpeed = 10.0;
    maxForce = 0.4;
    slowDownRadius = 400.0;
    
}

void Particle::setParam(ofVec2f _pos, ofVec2f _vel){
 
    pos.set( _pos);
    vel.set(_vel);
    
    lastPos.set( pos );
}


void Particle::addForce(ofVec2f force){
    acc += force;
    acc.limit( 5.0 );
}

void Particle::addRepulsionForce (const ofVec2f &fromPos){
    ofVec2f diff =  pos - fromPos;
    float strength = 1.0f - (diff.length() / 200.0f);
    addForce( diff.normalized() * strength );
}

void Particle::seek( const ofVec2f &dest ){
    //what is happening here????
    
    ofVec2f desired = dest - pos;
    cout << "desired :: " << desired << endl;
    
    if(dest.length() < slowDownRadius){
        float newMag = ofMap( desired.length(), 0, slowDownRadius, 0, maxSpeed);
        desired.normalize();
        desired *= newMag;
    } else {
        desired.normalize();
        desired *= maxSpeed;
    }
    
    ofVec2f steer = desired - vel;
    steer.limit(maxForce);
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
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();{
        ofTranslate( pos );
        float rotAmt = atan2( vel.y, vel.x );
        ofRotate( ofRadToDeg(rotAmt) + 90 );
        ofRect(0,0, 20, 40);
    }ofPopMatrix();
    
}