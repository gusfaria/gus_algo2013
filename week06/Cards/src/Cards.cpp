//
//  Cards.cpp
//  Cards
//
//  Created by Gustavo Faria on 07/10/13.
//
//

#include "Cards.h"


void Cards::setup(ofVec2f _pos){
    
    _pos = pos;

    for (int i = 0; i < 53; i++) {
        ofImage temp;
        temp.loadImage("img/" + ofToString(i) + ".png");
        cards.push_back(temp);
        cout << "img/" + ofToString(i) + ".png" << endl;
    }
    
    
    
}

void Cards::update(){
    
}

void Cards::draw(){
        for (int i = 0; i < cards.size(); i++) {
            cards[i].draw( pos , 72, 96);
        }
}