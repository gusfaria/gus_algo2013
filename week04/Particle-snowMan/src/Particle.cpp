



#include "Particle.h"



void Particle::setup( ofVec2f rVel ){
    vel = rVel;
    age = 0;
    lifespan = ofRandom(50, 150);
    
    pos.x = ofRandom(0,ofGetWindowWidth());
    bIsDead = false;
};

void Particle::update(){
    
//    float noise = ofNoise(pos.x * 0.005, pos.y*0.005, ofGetElapsedTimef() * 0.1) * 15.0;
    float agePct = 1 - ((float)age / (float)lifespan);
    
    
    
//        pos += ofVec2f( cos(noise), sin(noise) ) * (1.0-agePct);
        pos += vel;
        vel *= 1;
        
        age++;
        
        if( age > lifespan ) {
            bIsDead = true;
        }
};

void Particle::draw(){
    if( bIsDead ){
        return;
    }
    
    
    float agePct = 1-((float)age / (float)lifespan);
    ofSetColor(255);
    ofCircle( pos, 4.0 * agePct  );
};

