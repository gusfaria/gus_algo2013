//
//  Cards.h
//  Cards
//
//  Created by Gustavo Faria on 07/10/13.
//
//

#pragma once

#include "ofMain.h"

class Cards{
public:
    
    Cards(){};
    void setup(ofVec2f _pos, ofVec2f _vel);
    void update();
    void draw();
    
    vector <ofImage> cards;
    ofVec2f pos;
    ofVec2f vel;
    deque <ofVec2f> positionList;
    
};
