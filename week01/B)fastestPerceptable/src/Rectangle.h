//
//  Rectangle.h
//  fastestPerceptable
//
//  Created by Gustavo Faria on 01/09/13.
//
//

#ifndef __fastestPerceptable__Rectangle__
#define __fastestPerceptable__Rectangle__

#include "ofMain.h"
#include <iostream>

class Rectangle{
public:
	
	Rectangle();
	void update();
	void draw();
    
    ofPoint pos;
    float rectSpeed;
    
};


#endif /* defined(__fastestPerceptable__Rectangle__) */
