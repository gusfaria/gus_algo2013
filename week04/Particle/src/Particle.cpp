



#include "Particle.h"



void Particle::setup( ofVec2f rVel, ofPoint position ){
    vel = rVel;
    age = 0.1;
    lifespan = ofRandom(50, 250);
    
    pos = position;
    
//    pos.x = ofRandom(0,ofGetWindowWidth());
//    pos.y = ofRandom(0,ofGetWindowHeight());
    bIsDead = false;
};

void Particle::update(ofPoint position){
    
    float noise = ofNoise(pos.x * 0.005, pos.y*0.005, ofGetElapsedTimef() * 0.1) * 15.0;
    float agePct = 1 - ((float)age / (float)lifespan);
    //why this agePct variable is not universal? why do you need to set it on the update and the draw??
    
    if (position.y <= 500) {
        ofSetColor(200, 0, 0);
        pos += ofVec2f( cos(noise), sin(noise) ) * (1.0-agePct);
        pos += vel;
        vel *= 1;
    } else {
        ofSetColor(0, 0, 255);
        pos += vel;
        vel *= 1;
    }
    
    
        
        age++;
        
        if( age > lifespan ) {
            bIsDead = true;
        }
};

void Particle::draw(){
    if( bIsDead ){
        return;
    }
    
    float agePct = 1 - ((float)age / (float)lifespan);
    ofCircle( pos, 10.0 * agePct  );
};

