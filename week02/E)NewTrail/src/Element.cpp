//
//  Element.cpp
//  NewTrail
//
//  Created by Gustavo Faria on 10/09/13.
//
//

#include "Element.h"

Element :: Element (){
    
}
void Element :: setup(){
    
}
void Element :: update(){
    
}
void Element :: draw(){
    ofPushMatrix();{
        float angle = sin(ofGetElapsedTimef());
        pts.x +=angle;
        pts.y += 10;
        ofRotate(pts.x,mouseX, mouseY,0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofNoFill();
        ofSetColor(0,255,0);
        ofRect(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 50, 50);
    }ofPopMatrix();
    
}