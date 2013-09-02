//
//  Rectangle.cpp
//  fastestPerceptable
//
//  Created by Gustavo Faria on 01/09/13.
//
//

#include "Rectangle.h"

Rectangle::Rectangle(){
	
	
}

void Rectangle::update(){
    
    
    
}

void Rectangle::draw(){
    
	ofEnableAlphaBlending();
	ofSetColor(255, 255, 0, 255);
	ofRect(pos.x, pos.y, 40,40);
    
    
    //pct... what is? percentage of what?
    ofSetColor(0, 255, 0);
    ofDrawBitmapString(ofToString(pct), ofPoint(20,20));
}


void Rectangle::interpolate(float myPct){
    
    pct = myPct;
    
    pct = powf(myPct,2);
    
    pos.x = (1-pct) * posa.x + pct * posb.x;
	pos.y = (1-pct) * posa.y + pct * posb.y;
    
    
}