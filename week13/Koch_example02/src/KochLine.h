#pragma once

#include "ofMain.h"

class KochLine{
    
public:
    KochLine (ofVec2f _start, ofVec2f _end);
    void draw();
    ofVec2f start, end;
    
    
    ofVec2f a();
    ofVec2f b();
    ofVec2f c();
    ofVec2f d();
    ofVec2f e();
    
    float getLength();
    
};
