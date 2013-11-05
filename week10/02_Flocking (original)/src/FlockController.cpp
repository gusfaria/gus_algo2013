//
//  FlockController.cpp
//  Flocking
//
//  Created by Charlie Whitney on 10/20/13.
//
//

#include "FlockController.h"

FlockController::FlockController(){
}

void FlockController::addParticle( int numParticles ){
    for( int i=0; i<numParticles; i++ ){
        float rf = ofRandom(0, TWO_PI);
        
        ofVec3f randVec = ofVec3f( cos(rf), sin(rf), ofRandom(-1, 1) );
		ofVec3f pos = randVec * ofRandom( 100.0f, 600.0f );
		ofVec3f vel = -randVec;
        
        Boid b( pos, vel );
        boidList.push_back( b );
    }
}

void FlockController::applyForces( float zoneRadius, float separateThresh, float alignThresh) {
    float zoneRadiusSq = zoneRadius * zoneRadius;
    
    for( vector<Boid>::iterator b1=boidList.begin(); b1!=boidList.end(); ++b1 ){
        
        vector<Boid>::iterator b2 = b1 + 1;
        for( b2; b2!=boidList.end(); ++b2 ){
            
            // setup some vars
            ofVec2f dir = b1->pos - b2->pos;
            float lenSq = dir.lengthSquared();
            
            // We only want a boid to act on another boid if it's with zoneRadiusSq.
            // If they aren't within that distance, they are too far away and don't affect each other.
            if( lenSq < zoneRadiusSq ){
                
                float pct = lenSq / zoneRadiusSq;
                if( pct == 0 ){
                    pct = 0.0000001;
                }
                
                // seperation - The boids are too close to each other.  Apply a separation force;
                if( pct < separateThresh){
                    
                    float str = 1.0 - ofMap(pct, 0.0, separateThresh, 0.0, 1.0);
                    ofVec2f force = dir.normalized() * str * 0.03;
                    b1->applyForce( force );
                    b2->applyForce( -force );
                    
//                    float F = ( separateThresh/pct - 1.0f ) * 0.01;
//					ofVec3f force = dir.normalized() * F;
//					b1->applyForce( force );
//					b2->applyForce( -force );
                }

                // alignment - The boids are a medium distance from each other.  Apply an alignment force.
                else if( pct < alignThresh ){
                    float threshDelta		= alignThresh - separateThresh;
					float adjustedPercent	= ( pct - separateThresh )/threshDelta;
					float F					= ( 1.0f - ( cos( adjustedPercent * TWO_PI ) * -0.5f + 0.5f ) ) * 0.005;
                    
                    b1->applyForce( b2->vel.normalized() * F );
                    b2->applyForce( b1->vel.normalized() * F );
                }
                
                // cohesion - The boids are just a little too far from each other.  Apply an attraction force to bring them together.
                else{
                    float attractStrength = 0.01;
                    
                    float str = ofMap(pct, alignThresh, 1.0, 0.0, 1.0);
                    ofVec2f force = dir.normalized() * str * 0.03;
                    b1->applyForce( -force );
                    b2->applyForce( force );
                    
//                    float threshDelta		= 1.0f - alignThresh;
//					float adjustedPercent	= ( pct - alignThresh )/threshDelta;
//					float F					= ( 1.0f - ( cos( adjustedPercent * TWO_PI ) * -0.5f + 0.5f ) ) * attractStrength;
//                    
//					dir.normalize();
//					dir *= F;
//                    
//					b1->applyForce( -dir );
//					b2->applyForce( dir );
                }
            }
            
        }
        
        b1->pullToCenter( ofVec3f(0,0,0) );
    }
}

//--------------------------------------------------------------
void FlockController::update(){
    for( int i=0; i<boidList.size(); i++ ){
        boidList[i].update();
    }
}

//--------------------------------------------------------------
void FlockController::draw(){
    for( int i=0; i<boidList.size(); i++ ){
        boidList[i].draw();
    }
}