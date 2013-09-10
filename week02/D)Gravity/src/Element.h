
#ifndef __Gravity__Element__
#define __Gravity__Element__

#include <iostream>
#include "ofMain.h"

class Element{
public:
    Element();
    void setup(ofVec2f position, float grav, ofColor _myColor);
    void update();
    void draw();
    
    ofVec2f pos, vel;
    float gravity;
    ofColor myColor;
};



#endif /* defined(__Gravity__Element__) */
