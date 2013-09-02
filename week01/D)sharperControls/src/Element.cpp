
#include "Element.h"

//------------------------------------------------------------------
element::element(){
	zenoSpeed = 0.04;
}

//------------------------------------------------------------------
void element::draw() {
    
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(255,0,100, 10);
    ofCircle(ofGetWindowWidth()/2, ofGetWindowHeight()/2, size);
    
}

//------------------------------------------------------------------
void element::update(float zeno){
	size = zenoSpeed * zeno + (1-zenoSpeed) * size;
}