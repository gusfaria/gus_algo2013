#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    ofBackground(0);
    generation = 0;
    theta = 45;
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    theta = sin(ofGetElapsedTimef()) * 50;
}

//--------------------------------------------------------------
void testApp::branch(float length){
    
    generation ++;

    ofSetColor(255);
    ofPushMatrix();{
        ofLine(ofVec2f(0,0), ofVec2f(0,-length));
        ofTranslate(0, -length);
        
        float noise = ofNoise( generation, ofGetElapsedTimef() * 0.1);
        
        if ( length > 2 ) {
            ofPushMatrix();{
                ofRotate(45 + theta + noise * 10 );
                branch(length * 0.6667);
            }ofPopMatrix();
            ofPushMatrix();{
                ofRotate(-45 - theta + noise * 10);
                branch(length * 0.6667);
            }ofPopMatrix();
        }
    }ofPopMatrix();
    
    generation --;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPushMatrix();{
        ofTranslate(ofGetWindowWidth() / 2, ofGetWindowHeight());
        branch( 200 );
    }ofPopMatrix();
    
    ofSetColor(ofColor::lawnGreen, 30);
    ofRect(0, 0, ofGetWindowWidth(), ofGetWindowWidth());
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
//    theta = ofMap(y, 0, ofGetWindowHeight(), -180, 180);
    
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
