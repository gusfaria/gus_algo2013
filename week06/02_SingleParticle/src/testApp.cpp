#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0, 128, 1);
    ofRectMode(OF_RECTMODE_CENTER);
    
    for (int i = 0; i < 1; i++){
        addParticle(pos);
    }
    
    myCard.loadImage("img/1.png");
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < particleList.size(); i++){
        particleList[i].update();
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255);
    for (int i=0; i < particleList.size(); i++){
        particleList[i].draw();
    }
    
}

//--------------------------------------------------------------
void testApp::addParticle(ofPoint _pos){
    Particle tmp(pos);
    tmp.draw();
    particleList.push_back(tmp);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    pos.x = x;
    pos.y = y;
        
    addParticle(pos);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
