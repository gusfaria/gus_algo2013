#ifndef __clickToChange__Rectangle__
#define __clickToChange__Rectangle__

#include <iostream>
#include "ofMain.h"

class rectangle {
    
public:
	
    rectangle();
	
    void draw();
    void update();
    void interpolate(float myPct);
    
    ofPoint		pos;
    ofPoint		posa;
    ofPoint		posb;
    float		pct;
    
};


#endif /* defined(__clickToChange__Rectangle__) */
