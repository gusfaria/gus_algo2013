//
//  Element.h
//  NewTrail
//
//  Created by Gustavo Faria on 10/09/13.
//
//

#ifndef __NewTrail__Element__
#define __NewTrail__Element__

#include <iostream>
#include "ofMain.h"

class Element{
public:
    Element();
    void setup();
    void update();
    void draw();

    ofVec2f pts;
};

#endif /* defined(__NewTrail__Element__) */
