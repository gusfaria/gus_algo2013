#include "Element.h"

Element::Element (){
    
    gravity = 9.8/6;

}

void Element:: setup(ofVec2f position, float grav, ofColor _myColor){
    pos = position;
    gravity = grav;
    vel.y = ofRandom(0,10);
    myColor = _myColor;
}

void Element :: update(){
    vel.y += gravity;
    pos.y += vel.y;
}

void Element :: draw(){
    ofSetColor(myColor);
    ofCircle(pos, 20);
    
    if(pos.y > ofGetWindowHeight()-20){
        pos.y = ofGetWindowHeight()-20;
        vel.y *= -1;
    }
}

