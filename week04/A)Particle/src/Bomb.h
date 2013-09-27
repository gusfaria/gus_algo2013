//
//  Bomb.h
//  Particle
//
//  Created by Gustavo Faria on 27/09/13.
//
//

#include "ofMain.h"

class Bomb{
public:
    Bomb();
    void setup();
    void update();
    void draw();
    bool bExploded();
    
    ofVec2f pos;
    ofVec2f vel;
    ofColor color;
    
    float initVel;
    float size;
};
