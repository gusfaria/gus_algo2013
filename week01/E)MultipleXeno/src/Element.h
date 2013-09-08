//
//  Element.h
//  MultipleXeno
//
//  Created by Gustavo Faria on 30/08/13.
//
//

#ifndef __MultipleXeno__Element__
#define __MultipleXeno__Element__

#include <iostream>
#include "ofMain.h"

#endif /* defined(__MultipleXeno__Element__) */


class Element{
    public:
    Element();
    void update();
    void draw(int r, int g, int b, int posY);
    void zenoToPoint(float catchSpeed, float catchX);
    
    ofPoint pos;
};