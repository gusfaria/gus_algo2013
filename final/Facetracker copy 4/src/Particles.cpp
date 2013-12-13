//
//  Particles.cpp
//  ofApp
//
//  Created by Gustavo Faria on 02/12/13.
//
//

#include "Particles.h"


Particles::Particles(){
    friction = ofRandom(0.8,1.5);
    pizza.loadImage("pizza.png");
    vel.set(ofRandom(-3,5),ofRandom(-3,5));

}

void Particles::update(){
    vel += acc ;
    pos += vel;
    
    if ( pos.x <= 0 || pos.x >= ofGetWindowWidth() ) vel.x *= -1;
    if ( pos.y <= 0 || pos.y >= ofGetWindowHeight() ) vel.y *= -1;

}

void Particles::draw(){
    ofCircle(pos, 4);
    glPushMatrix();{
        ofTranslate(pos);
        ofSetColor(255);
        pizza.draw(-25,-25,50, 50);
    } glPopMatrix();

}