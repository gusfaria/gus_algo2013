#ifndef __MultipleXeno__Element__
#define __MultipleXeno__Element__

#include <iostream>
#include "ofMain.h"

class Element{
    public:
    Element();
    void update();
    void draw();
    void zenoToPoint(float catchSpeed, float catchX, float catchY);
    
    ofPoint pos;
};

#endif /* defined(__MultipleXeno__Element__) */
