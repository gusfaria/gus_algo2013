#include "Mover.h"

Mover :: Mover()
{
    pos = ofGetWindowSize() /2;
    velocity.x = ofRandom(-5.0, 5.0);
    velocity.y = ofRandom(-5.0, 5.0);
}

void Mover :: update()
{
    acceleration = (mousePos - pos) * 0.01;
    
    velocity += acceleration;
    
    pos += velocity;
    velocity *= 0.97;
}

void Mover :: draw()
{
    ofCircle(pos, 20);
    
}
