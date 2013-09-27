



#include "Particle.h"


void Particle::setup(ofVec2f _Pos, float velMult, float hue){
    pos = _Pos;
//    vel.set(ofRandom(-2,2) * 5, ofRandom(-2,2) * 5);
    acc.y = 0.5;
    size = ofRandom(2,5);
    color.setHsb(hue,  ofRandom(255), ofRandom(255));
    
    vel.x = ofRandom(-velMult / 2.0, velMult / 2.0);
    vel.y = ofRandom(-velMult / 2.0, velMult / 2.0 + 1.0);
    
    age = 0;
    life = ofRandom(80,240);
};

void Particle::update(){
    float pct = 1.0 - (float)age / (float)life;
    size = pct * size;
    
    float noise = ofNoise(pos.x * 0.5, pos.y * 0.5, ofGetElapsedTimef() * 0.5) * 10.0;
    pos += ofVec3f( cos(noise), sin(noise)) * 1.0-pct;
    acc.y *= 0.001;
    vel.y += acc.y;
    pos += vel;
    age++;
};

void Particle::draw(){
    ofSetColor(color);
    ofCircle(pos, size);
    
};

bool Particle::bIsDied(){
    if (age >= life ) {
        return true;
    } else {
        return false;
    }
    
}
