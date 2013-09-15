#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    pos = (ofGetWindowSize()/2);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
//    ofPushMatrix();{
//        ofSetRectMode(OF_RECTMODE_CENTER);
//        ofTranslate(pos);
//        ofRotateZ(ofGetElapsedTimef() * 30.0);
//        ofNoFill();
//        ofSetColor(ofColor::magenta);
//        ofRect(0,0,50,50);
//    }ofPopMatrix();
    
    float angle = (ofGetElapsedTimef() * 3);
    float x = radius * cos( angle );
    float y = radius * sin( angle );
    pos.x = x;
    pos.y = y;

    rectList.push_back(pos);
    
    ofPushMatrix();{
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
        ofRotateZ(ofGetElapsedTimef() * -30.0);
        ofNoFill();
        ofSetColor(ofColor::magenta);
        ofRect(pos,100,100);
    }ofPopMatrix();
    
    
    
    
    
    ofPushMatrix();{
        ofSetRectMode(OF_RECTMODE_CORNER);
        ofFill();
        ofSetColor(0,1);
        ofRect(0,0, ofGetWindowWidth(), ofGetWindowHeight());
    } ofPopMatrix();
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
