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
    void setup(ofVec2f _pos);
    void update();
    void draw();
    
    vector <ofImage> cards;
    ofVec2f pos;
    
    
};
