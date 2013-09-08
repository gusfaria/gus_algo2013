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

void Element::draw(int r, int g, int b, int posY){
    pos.y = posY;
    
    ofSetColor(r, g, b, 70);
    ofCircle(pos.x,pos.y,30);
    
}

void Element::zenoToPoint(float catchSpeed, float catchX){
    
    float catchUpSpeed = catchSpeed;
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
//	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;

    
}