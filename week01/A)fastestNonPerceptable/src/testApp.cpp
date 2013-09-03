#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    
    myRect.rectSpeed = 0.001;
    myRect.pos.y = ofGetWindowHeight()/2;
    
    speed = 0;
    inchesSec = 0;
    milesHour = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    myRect.update();
    
    //inches in a pixel = 0.0093in
    
    speed = myRect.rectSpeed * ofGetFrameRate();
    inchesSec = (speed * 11.3125) / ofGetWindowWidth();
    milesHour = (inchesSec*3600) / 63360;
}

//--------------------------------------------------------------
void testApp::draw(){
    myRect.draw();
    
    if(myRect.pos.x >= ofGetWindowWidth()) myRect.pos.x=0;
    
//    ofDrawBitmapString("Position:" + ofToString(myRect.pos.x), ofPoint(10,20));
    ofDrawBitmapString("Speed:" + ofToString(speed), ofPoint(10,35));
    ofDrawBitmapString("Inches per Second:" + ofToString(inchesSec), ofPoint(10,50));
    ofDrawBitmapString("Miles per hour:" + ofToString(milesHour), ofPoint(10,65));
    
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
