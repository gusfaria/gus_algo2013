#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofNoFill();
//    ofSetColor(255);
//    ofRect(mouseX, mouseY, 50, 50);
    
    
//    ofPushMatrix();{
//        float angle = sin(ofGetElapsedTimef());
//        pts.x +=angle;
//        pts.y += 10;
//    ofRotate(pts.x,mouseX, mouseY,0);
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofNoFill();
//    ofSetColor(0,255,0);
//    ofRect(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 50, 50);
//    }ofPopMatrix();

    
    ofPushMatrix();{
        ofSetRectMode(OF_RECTMODE_CORNER);
        ofFill();
        ofSetColor(0, 0, 0, 10);
        ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    }ofPopMatrix();
    

    

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
