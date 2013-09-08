#ifndef __MultipleXeno__Element__
#define __MultipleXeno__Element__

#include <iostream>
#include "ofMain.h"

class Element{
    public:
    Element();
    void update();
    void draw();
    void zenoToPoint(float catchSpeed, ofVec2f catchPos);
    
    ofVec2f pos;
};

#endif /* defined(__MultipleXeno__Element__) */
