#ifndef __MultipleXeno__Element__
#define __MultipleXeno__Element__

#include <iostream>
#include "ofMain.h"

class Element{
    public:
    Element();
    void setup();
    void upload(float catchSpeed, ofVec2f catchPos);
    void draw();
    
    
    ofVec2f pos;
    float w;
};

#endif /* defined(__MultipleXeno__Element__) */
