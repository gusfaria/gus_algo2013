//
//  Bold.cpp
//  Flocking
//
//  Created by Gustavo Faria on 22/10/13.
//
//

#include "Bold.h"


Bold::Bold () {
    damping = ofRandom(0.95, 0.99);
    
    
}


void Bold::applyForce ( ofVec3f force ){
    acc += force;

    
}


void Bold::pullToCenter( ofVec3f center ){
    ofVec3f dir = pos - center;
    float dist = dir.length();
    float maxDistance = 300.0;
    
    if ( dist > maxDistance ){
        dir.normalize();
        vel -= dir * ( dist - maxDistance ) * 0.0001f;
        
    }
    
}

void Bold::update(){
    float minSpeed = 1.0;
    vel += acc;
    
    vel.limit (3.0); //putting a limit to the maximum number vel can get!
    if (vel.lengthSquared() < minSpeed * minSpeed) {
        vel = vel.normalized() * minSpeed;
        
    }
    pos += vel;
    vel *= damping;
    acc.set(0);
}

void Bold::draw(){
    cout << "hello" << endl;
    ofSetColor(255);
    ofCircle(pos,2);
    
    ofSetColor(0,255,0);
    ofLine( pos, pos - vel * 10.0);

}