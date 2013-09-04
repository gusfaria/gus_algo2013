//
//  Rectangle.cpp
//  exampleA
//
//  Created by Gustavo Faria on 03/09/13.
//
//

#include "Rectangle.h"

Rectangle :: Rectangle(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    catchUpSpeed = 0.1f;
}

void Rectangle:: xenoToPoint (float catchX, float catchY){
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}

void Rectangle:: draw(){
    ofSetColor(255* (pos.y / ofGetWindowHeight()),0,0);
    ofRect(pos.x, pos.y, 30, 30);
}

