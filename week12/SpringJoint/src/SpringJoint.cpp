//
//  SpringJoint.cpp
//  SpringJoint
//
//  Created by Gustavo Faria on 12/11/13.
//
//

#include "SpringJoint.h"


void SpringJoint::applyForce(ofVec2f force){
    acc += force;
    
}

void SpringJoint::update(){
    vel += acc;
    pos += vel;
    vel *= 0.95;
    
    acc.set(0);
    
}

void SpringJoint::draw(){
    ofCircle(pos, 10);
    
}