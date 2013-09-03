#include "Rectangle.h"

rectangle::rectangle(){

}


void rectangle::draw() {
    ofSetColor(255);
    ofCircle(posa.x, posa.y, 5);
    ofCircle(posb.x, posb.y, 5);
    ofLine(posb.x,posb.y, posa.x, posa.y);
    
    ofFill();
    ofSetColor(0,0,255);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofRect(pos.x, pos.y, 30,30);

}

void rectangle::interpolate(float myPct){

    pct = myPct;
	pos.x = (1-pct) * posa.x + (pct) * posb.x;
	pos.y = (1-pct) * posa.y + (pct) * posb.y;
    
}