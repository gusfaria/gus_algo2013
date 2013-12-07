//
//  Particle.cpp
//
//  Created by Gustavo Faria on 06/12/13.
//
//

#include "Particle.h"

Particle::Particle(){
    setParams(0,0,0,0);
    damping = ofVec2f(0, 0.01);
    pSize.set(10,10);
}

//void Particle::addForce(ofVec2f force){
//    frc += force;
//}
//
//void Particle::addDampingForce(){
//    frc = frc + vel * damping;
//}
//
//void Particle::resetForces(){
//    frc.set( 0,0 );
//}

void Particle::setParams(float px, float py, float vx, float vy){
    pos.set(px,py);
    vel.set(vx,vy);
}

void Particle::update(){
    vel = vel + frc;
    pos = pos + vel;
}

void Particle::draw(){
    ofSetColor(ofColor::magenta);
    ofRect(pos, pSize.x, pSize.y);
}