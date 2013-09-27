

#include "Particle.h"


Particle::Particle(){
    setParams(0, 0, 0, 0);
    damping.set(0,0);
    
}

void Particle::setParams(float px, float py, float vx, float vy){
    pos.set(px,py);
    vel.set(vx,vy);
}

void Particle::addForce(ofVec2f force){
    frc += force;
}

void Particle::resetForces(){
    frc.set(0,0);
}

void Particle::addDampingForce(){
    frc = frc - vel * damping;
}

void Particle::update(){
    vel += frc;
    pos += vel;
}

void Particle::draw(){
    ofCircle(pos, 3);
}