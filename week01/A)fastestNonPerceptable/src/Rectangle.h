//
//  Rectangle.h
//  fastestNonPerceptable
//
//  Created by Gustavo Faria on 30/08/13.
//
//

#ifndef __fastestNonPerceptable__Rectangle__
#define __fastestNonPerceptable__Rectangle__

#include <iostream>
#include "ofMain.h"

#endif /* defined(__fastestNonPerceptable__Rectangle__) */


class Rectangle{
public:
	
	Rectangle();
	void update();
	void draw();
    
    float rectSpeed;
    ofPoint pos;
};