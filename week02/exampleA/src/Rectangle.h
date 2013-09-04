//
//  Rectangle.h
//  exampleA
//
//  Created by Gustavo Faria on 03/09/13.
//
//

#ifndef __exampleA__Rectangle__
#define __exampleA__Rectangle__

#include <iostream>
#include "ofMain.h"

class Rectangle {
public:
    
    Rectangle();
    void xenoToPoint (float catchX, float catchY);
    void draw();
    
    ofPoint pos, targetPos;
    float catchUpSpeed;
};






#endif /* defined(__exampleA__Rectangle__) */
