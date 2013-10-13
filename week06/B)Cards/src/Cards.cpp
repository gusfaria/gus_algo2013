//
//  Cards.cpp
//  Cards
//
//  Created by Gustavo Faria on 07/10/13.
//
//

#include "Cards.h"


void Cards::setup(ofVec2f _pos, ofVec2f _vel){
    pos = _pos;
    
    vel = _vel;

    for (int i = 1; i < 52; i++) {
        ofImage temp;
        
        pos = ofVec2f(pos);

        positionList.push_back(pos);
        
        temp.loadImage("img/" + ofToString(i) + ".png");
        cards.push_back(temp);
        cout << "img/" + ofToString(i) + ".png" << endl;
    }
    
}

void Cards::update(){
    float gravity = 0.98;
    vel.y += gravity;
    pos += vel;
    
    positionList.push_back(pos);
    
    while (positionList.size() > 52) {
        positionList.pop_front();
    }
    
    
}

void Cards::draw(){
        for (int i = 0; i < cards.size(); i++) {
            cards[i].draw( positionList[i], 72, 96);
        }
    
    if(pos.x > ofGetWindowWidth() - 72 || pos.x < 0){
        vel.x *= -1;
    }
    
    if(pos.y > ofGetWindowHeight()-96){
        vel.y *= -1;
    }
    
}





