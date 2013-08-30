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

void Element::draw(int cor){

    ofSetColor(cor, 0, 0);
    ofCircle(pos.x,pos.y,10);
    
}

void Element::zenoToPoint(float catchX, float catchY){
    
    float catchUpSpeed = 0.1f;
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    
}