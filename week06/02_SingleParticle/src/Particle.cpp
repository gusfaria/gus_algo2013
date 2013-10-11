//
//  Particle.cpp
//  SingleParticle
//
//  Created by Charlie Whitney on 9/23/13.
//
//

#include "Particle.h"

Particle::Particle(ofPoint _pos) {
    
    for (int i = 0; i < 53; i++) {
        ofImage temp;
        temp.loadImage("img/" + ofToString(i) + ".png");
        cards.push_back(temp);
        cout << "img/" + ofToString(i) + ".png" << endl;
    }
    pos.set(100,100);
    pos = _pos;
    acc = 0.98;
}


void Particle::update() {
//    vel.set(ofRandom(-1,2), ofRandom(-1,3));
//
    pos += vel;
    vel *= acc;
}

void Particle::draw() {
    ofCircle(pos.x, pos.y, 3);
    
    for (int i = 0; i < 53; i++) {
        cards[i].draw( pos, 72, 96 );
    }

    
}