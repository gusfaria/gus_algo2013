//
//  FlockControler.cpp
//  Flocking
//
//  Created by Gustavo Faria on 22/10/13.
//
//

#include "FlockControler.h"


FlockControler::FlockControler(){
    
};

void FlockControler::addParticle ( int numParticles ){
//the number just go in the header
    for (int i = 0; i > numParticles; i++) {
        
        // I was getting bad results, so I looked up uniform sphere distribution and got this: http://mathworld.wolfram.com/SpherePointPicking.html
        float phi = ofRandom( 0, TWO_PI );
		float costheta = ofRandom( -1.0f, 1.0f );
		
		float rho = sqrt( 1.0f - costheta * costheta );
		float x = rho * cos( phi );
		float y = rho * sin( phi );
		float z = costheta;
		
        ofVec3f randVec(x, y, z);
        
		ofVec3f pos = randVec * ofRandom( 100.0f, 600.0f );
		ofVec3f vel = -randVec;
        
        
        Bold b;
        boldList.push_back( b );
        
        b.pos = pos;
        b.vel = vel;
    }
}

void FlockControler::applyForces (float zoneRadius, float separateThresh, float alignThresh){
    
}


void FlockControler::update(){
    for (int i = 0; i < boldList.size(); i++) {
        boldList[i].pullToCenter(ofVec3f(0,0,0));
        boldList[i].update();
        
    }
}

void FlockControler::draw(){

    for (int i = 0; i < boldList.size(); i++) {
        boldList[i].draw();
    }
    
    
}