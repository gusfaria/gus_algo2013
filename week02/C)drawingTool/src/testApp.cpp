#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetCircleResolution(60);
    
    ofSetBackgroundAuto(false);
    
    ofSeedRandom();
    vel.x = ofRandom(-3,3);
    vel.y = ofRandom(-5,5);

}

//--------------------------------------------------------------
void testApp::update(){
    
    pos += vel;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    if(pos.x > ofGetWindowWidth() || pos.x < 0) vel.x *= -1;
    if(pos.y > ofGetWindowHeight() || pos.y < 0) vel.y *= -1;
    
    for (int i = 0; i<20; i++) {
        ofSetColor(255, 0, 0, 9);
        ofCircle(pos, 25);
    }

    
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
