

#include "Particle.h"


Particle :: Particle( ofVec2f   position    ){
    pos = position;
    radius = ofRandom(1.0,4.0);
    grayValue = 255;
    
}

void Particle :: draw(){
    ofSetColor(grayValue);
    ofCircle(pos, radius);
    
}