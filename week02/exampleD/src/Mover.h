//
//  Mover.h
//  exampleD
//
//  Created by Gustavo Faria on 03/09/13.
//
//

#pragma once

#include "ofMain.h"


class Mover{
public:
    Mover();
    void update();
    void draw();
    
    ofVec2f pos, mousePos;
    ofVec2f acceleration, velocity;
    
};
