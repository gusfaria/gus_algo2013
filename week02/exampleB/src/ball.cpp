//
//  balll.cpp
//  exampleB
//
//  Created by Gustavo Faria on 03/09/13.
//
//

#include "ball.h"

Ball :: Ball(){
    ofSeedRandom();
    xVelocity = ofRandom(0.0,1.0);
    yVelocity = ofRandom(0.0,1.0);
    
    pos.x = ofGetWindowWidth() *0.5;
    pos.y = ofGetWindowHeight() *0.5;
}

void Ball ::  update(){
    pos.x += xVelocity * 10;
    pos.y += yVelocity * 10;

    if(pos.x < 0 || pos.x > ofGetWindowWidth()) xVelocity *= -1;
    if(pos.y < 0 || pos.y > ofGetWindowHeight()) yVelocity *= -1;

    
}

void Ball ::  draw(){
    ofSetColor(100,0,255);
    ofCircle(pos.x, pos.y, 10);
}