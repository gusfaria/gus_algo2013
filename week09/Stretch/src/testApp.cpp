#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    pos.set(ofGetWindowSize()/2);
    velY = 0.5;
    acc = 0.98;
    ball.set(50,50);
}

//--------------------------------------------------------------
void testApp::update(){
    ofBackground(100,100,100,50);
    velY += acc;
    pos.y += velY;
    

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255, 0, 0);
    ofEllipse(pos, ball.x,ball.y);
    
    if(pos.y > ofGetWindowHeight()-30){

        pos.y = ofGetWindowHeight()-30;
        velY *= -1;
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
