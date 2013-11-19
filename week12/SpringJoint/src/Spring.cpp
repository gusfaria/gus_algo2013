//
//  Spring.cpp
//  SpringJoint
//
//  Created by Gustavo Faria on 12/11/13.
//
//

#include "Spring.h"

void Spring::set ( SpringJoint *_s1, SpringJoint *_s2, float _k, float _restLength ){
    
    s1 = _s1;
    s2 = _s2;
    k = _k;
    restLenght= _restLength;
    
}


void Spring::update(){
    ofVec2f  force = s2 ->pos - s1 ->pos; //direction
    float len = force.length();
    float stretchLen = len - restLenght;
    
    force.normalize();
    force *= -1 * k * stretchLen;
    
    s1 -> applyForce( -force );
    s2 -> applyForce( force );
}


void Spring::draw(){
    ofLine( s1->pos, s2->pos );
    
}

