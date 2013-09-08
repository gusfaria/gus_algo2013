//
//  Element.cpp
//  MultipleXeno
//
//  Created by Gustavo Faria on 30/08/13.
//
//

#include "Element.h"

Element::Element(){
    pos.x = ofRandom(0, ofGetWindowWidth());
    pos.y = ofRandom(0, ofGetWindowHeight());
    
}

void Element::update(){
    
    
    
}

void Element::draw(){
    ofSetColor(0, 0, 255);
    ofCircle(pos.x,pos.y,30);
    
}

void Element::zenoToPoint(float catchSpeed, ofVec2f catchPos){
    
    float catchUpSpeed = catchSpeed;
	pos = catchUpSpeed * catchPos + (1-catchUpSpeed) * pos;
//    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;

    
}