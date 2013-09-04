//
//  balll.h
//  exampleB
//
//  Created by Gustavo Faria on 03/09/13.
//
//

#ifndef __exampleB__balll__
#define __exampleB__balll__

#include <iostream>
#include "ofMain.h"

class Ball {
public:
    
    Ball();
    void update();
    void draw();
    
    ofVec2f pos;
    float xVelocity;
    float yVelocity;
};

#endif /* defined(__exampleB__balll__) */
