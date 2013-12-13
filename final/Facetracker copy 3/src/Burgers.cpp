//
//  Burgers.cpp
//  ofApp
//
//  Created by Gustavo Faria on 13/12/13.
//
//

#include "Burgers.h"

Burger::Burger(){
    friction = ofRandom(0.8,1.5);
    burger.loadImage("burger.png");
    vel.set(ofRandom(-3,5),ofRandom(-3,5));
    
}

void Burger::update(){
    vel += acc ;
    pos += vel;

    if ( pos.x <= 0 || pos.x >= ofGetWindowWidth() ) vel.x *= -1;
    if ( pos.y <= 0 || pos.y >= ofGetWindowHeight() ) vel.y *= -1;
}

void Burger::draw(){
    ofCircle(pos, 4);
    glPushMatrix();{
        ofTranslate(pos);
        ofSetColor(255);
        burger.draw(-25,-25,50, 50);
    } glPopMatrix();
    
}