//
//  VectorField.h
//  myVectorField
//
//  Created by Gustavo Faria on 18/10/13.
//
//

#pragma once
#include "ofMain.h"

class VectorField{
    public:
    
    VectorField();
    
    void setup(int width, int height, int res);
    void update();
    void draw();
    
    void setPerlin();
    void setPerlin( float scale );

    void mouseInfluence(float x, float y);
    
    void addLinearForce( float x, float y, ofVec2f dir, float influence );
    
    void useImage();
    
    ofVec2f getForceAtScreenPos(ofVec2f pos);
    
    vector <vector<ofVec2f> > flowList;
    
    int fieldWidth, fieldHeight, resolution;
    
    ofImage img;
    
};


