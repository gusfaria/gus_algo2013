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
    
    pos.x += rectSpeed;
    
}

void Rectangle::draw(){
    ofSetColor(0, 200, 200);
    ofRect(pos.x, pos.y, 40, 40);
}
