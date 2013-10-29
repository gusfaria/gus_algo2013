//
//  Element.cpp
//  AnimationPrinciples
//
//  Created by Gustavo Faria on 28/10/13.
//
//

#include "Element.h"


Element::Element(){
    color.setHsb(150, 244, 255);
    vel.y = 12;
    pos.set(ofGetWindowWidth() / 2- 100, ofGetWindowHeight() + 100);
    acc = 0.98;
    increment = 1;
    
}

void Element::setup(){
//    color.setHsb(150, 244, 255);
    vel.y = 12;
    pos.set(ofGetWindowWidth() / 2- 100, ofGetWindowHeight() + 100);
    acc = 0.98;
    rectSize = 100;
}

void Element::update(){
    vel.y *= acc;
    pos.y -= vel.y;
}

void Element::draw(){
//    color = _color;
    //rectSize = ;
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(color);
    ofRect(pos, rectSize + increment, rectSize + increment);

}

void Element::reset(){
    vel.y = 12;
    pos.set(ofGetWindowWidth() / 2- 100, ofGetWindowHeight() + 100);
    acc = 0.98;
    rectSize = 100;
}