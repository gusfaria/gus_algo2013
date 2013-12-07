//
//  KochLine.cpp
//  Koch
//
//  Created by Gustavo Faria on 19/11/13.
//
//

#include "KochLine.h"


KochLine::KochLine(ofVec2f _start, ofVec2f _end){
    start = _start;
    end = _end;
}

void KochLine::draw(){
    ofLine( start,end );
}

float KochLine::getLength(){
    return start.distance(end);
}



ofVec2f KochLine::a(){
    return start;
    
}

ofVec2f KochLine::b(){
    ofVec2f line = (end - start) * 0.333333;
    return start + line;
    
}

ofVec2f KochLine::c(){
    ofVec2f line = (end - start) * 0.333333;
    line.rotate( -60 ); // rotate up
    return b() + line;
    
}

ofVec2f KochLine::d(){
    ofVec2f line = (end - start) * 0.666667;
    return start + line;
    
}

ofVec2f KochLine::e(){

    return end;
}