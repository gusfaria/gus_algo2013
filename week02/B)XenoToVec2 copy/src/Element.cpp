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
    w = 20;
}

void Element::setup(ofColor _myColor){
    
}

void Element::upload(float catchSpeed, ofVec2f catchPos){
    
    float catchUpSpeed = catchSpeed;
	pos = catchUpSpeed * catchPos + (1-catchUpSpeed) * pos;
}

void Element::draw(){
    ofNoFill();
//    color.g = ofMap(pos.y, 0, ofGetWindowHeight(), 0, 255);
    ofSetColor(myColor);
    ofRect(pos.x,pos.y,w,w);
    
}

