//
//  Element.cpp
//  drawingTool
//
//  Created by Gustavo Faria on 09/09/13.
//
//

#include "Element.h"

Element::Element (){
    pos.x = ofGetWindowWidth() / 2.0;
    pos.y = ofGetWindowHeight() / 2.0;
    velocity.x = ofRandom(-5.0, 5.0);
    velocity.y = ofRandom(-5.0, 5.0);
    rectSize = 15;

}

void Element:: setup(ofVec2f position){
    position = pos;
}

void Element :: update(){
    ofVec2f accel = (mousePos - pos) * 0.01f;
    velocity += accel;
    
    pos += velocity;
    velocity *= 0.97;

}

void Element :: draw(){

    ofNoFill();
    ofRect(pos,rectSize,rectSize);
}
