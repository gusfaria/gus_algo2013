//  Particle.cpp
//  GUI_Particles
//
//  Created by Gustavo Faria on 30/09/13.


#include "Particle.h"

Particle::Particle(float particleSize, ofColor _color){
    
    setParams(0,0,0,0);
    pSize = particleSize;
    damping = ofVec2f(0, 0.01);
    bubble.loadImage("bubble.png");
    
    color = _color;

}

void Particle::addForce(ofVec2f force){
    frc += force;
    
}

void Particle::addDampingForce(){
    frc = frc + vel * damping;
}

void Particle :: resetForces(){
    frc.set( 0,0 );
}

void Particle::setParams( float px, float py, float vx, float vy   ){
    pos.set(px,py);
    vel.set(vx,vy);
    
}

void Particle::update(){
    vel = vel + frc;
    pos = pos + vel;
    

    
}

void Particle::draw(){
//    ofCircle( pos.x,pos.y, pSize );
    ofSetColor(color);
    bubble.draw(pos.x, pos.y, pSize,pSize);
}