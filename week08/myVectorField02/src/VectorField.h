//
//  VectorField.h
//  myVectorField02
//
//  Created by Gustavo Faria on 18/10/13.
//
//

#pragma once
#include "ofMain.h"

class VectorField{
    public:
    int fieldWidth;
    int fieldHeight;
    int fieldSize;
    
    int externalWidth;
    int externalHeight;
    
    vector <ofVec2f> field;
    
    vectorField();
    virtual ~vectorField();

    void setupField(int innerW, int innerH, int outerW, int outerH);
    
};