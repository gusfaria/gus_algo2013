//
//  Element.cpp
//  drawingTool
//
//  Created by Gustavo Faria on 09/09/13.
//
//

#include "Element.h"

Element::Element (){
    
}

void Element:: setup(ofVec2f position){
    position = pos;
}

void Element :: update(){

}

void Element :: draw(){
    float angle = sin(ofGetElapsedTimef()*0.5);
    element.z += angle;
    ofRotate(element.z, pos.x,pos.y, 0);
    ofNoFill();
    ofSetColor(255);
    element.x += 6;
    element.y += 6;
    ofRect(pos, element.x, element.y);
}
