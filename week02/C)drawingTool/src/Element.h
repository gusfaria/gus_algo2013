//
//  Element.h
//  drawingTool
//
//  Created by Gustavo Faria on 09/09/13.
//
//

#ifndef __drawingTool__Element__
#define __drawingTool__Element__

#include <iostream>
#include "ofMain.h"

class Element{
public:
    Element();
    void setup(ofVec2f position);
    void update();
    void draw();
    
    ofVec3f element;
    float size;
    ofVec2f pos;
    
};

#endif /* defined(__drawingTool__Element__) */
