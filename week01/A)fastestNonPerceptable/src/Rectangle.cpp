//
//  Rectangle.cpp
//  fastestNonPerceptable
//
//  Created by Gustavo Faria on 30/08/13.
//
//

#include "Rectangle.h"


Rectangle::Rectangle(){	
	
}

void Rectangle::update(){
    
    pos.x += rectSpeed;
    
}

void Rectangle::draw(){
    ofSetColor(255, 255, 0);
    ofRect(pos.x, pos.y, 30, 30);
}