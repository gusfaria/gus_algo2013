#include "Element.h"

Element::Element (){
    vel.y = 1;
}

void Element:: setup(ofVec2f position, float grav){
    pos = position;
    gravity = grav;

    
}

void Element :: update(){
    vel.y += gravity;
    pos.y += vel.y;
}

void Element :: draw(){
    ofCircle(pos, 20);
    
    if(pos.y > ofGetWindowHeight()){
        vel.y *= -1;
    }
}

