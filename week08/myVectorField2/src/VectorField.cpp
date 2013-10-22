//
//  VectorField.cpp
//  myVectorField
//
//  Created by Gustavo Faria on 18/10/13.
//
//

#include "VectorField.h"


VectorField::VectorField(){
    
}

void VectorField:: setup(int width, int height, int res){
    fieldWidth = width;
    fieldHeight = height;
    resolution = res;
    
    int cols = fieldWidth/resolution;
    int rows = fieldHeight/resolution;
    
    for (int y = 0; y < rows; y++) {
        vector <ofVec2f> myList;
        
        for (int x = 0; x < cols; x++) {
            ofVec2f direction(ofRandom(-10,10),ofRandom(-10,10));
            myList.push_back( direction );
        }
        
        flowList.push_back( myList );
    }
    
    img.loadImage("img.jpg");
    
}

void VectorField:: update(){

    
}

ofVec2f VectorField:: getForceAtScreenPos( ofVec2f pos ){
    float pctX = pos.x / fieldWidth;
    float pctY = pos.y / fieldHeight;
    
    int cols = fieldWidth / resolution;
    int rows = fieldHeight / resolution;
    
    int xVal = ofClamp( pctX * cols, 0, cols-1 );
    int yVal = ofClamp( pctY * rows, 0, rows-1 );
    
    ofVec2f newPos;
    newPos.set( flowList[yVal][xVal] );
    
    return newPos;
}

void VectorField::setPerlin() {
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            float noise = ofMap( ofNoise(x*0.05, y*0.05), 0, 1, 0, TWO_PI);
            flowList[y][x].set( ofVec2f( cos(noise)*20, sin(noise)*20 ) );
        }
    }
}

void VectorField::setPerlin( float scale) {
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            float noise = ofMap( ofNoise(x*scale, y*scale), 0, 1, 0, TWO_PI);
            flowList[y][x].set( ofVec2f( cos(noise)*20, sin(noise)*20 ) );
        }
    }
}


void VectorField::mouseInfluence(float x, float y){
    ofVec2f dir(x, y);
   
    
}

void VectorField::useImage(){
    
};

    //directly from bernardo's schorrs code!!!!!
    // https://github.com/bschorr/schorr_algo2013/tree/master/week_08/algo_week_08_01_vectorFieldParticle1
void VectorField::addLinearForce( float x, float y, ofVec2f dir, float influence ) {
    
    ofVec2f mousePos(x, y);
    
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            
            ofVec2f np( x*resolution, y*resolution );
            
            if( np.distance(mousePos) < influence ){
                flowList[y][x] += dir*3;
            }
        }
    }
}



void VectorField:: draw(){
    img.draw(0,0);
    for (int y = 0; y < flowList.size(); y++) {
        for (int x = 0; x < flowList[y].size(); x++) {
            ofVec2f tmpPos(x*resolution, y*resolution);
            ofLine(tmpPos, tmpPos + flowList[y][x] );
        }
    }
    
}




