

//With assistance of Anthony Marafat's code:
//https://github.com/SafetyOrange/Algorithmic-Animation-2013/tree/master/Week%209/squatch


#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(15);
    ofEnableAlphaBlending();
    ofBackground(200, 200, 200);
    
    ofSetCircleResolution(100);
    
    vel = 2;
    acc = 0.7;
    pos.set(0, 200);
    threshold = ofGetWindowHeight() - 150 - h;
    w = 150;
    h = 150;
}

//--------------------------------------------------------------
void testApp::update(){
    vel += acc;
    pos.x += 2;
    pos.y += vel;
    
    if(pos.y - 75 > ofGetWindowHeight()-75){
        
        pos.y = ofGetWindowHeight()-75;
        vel *= -1;
    }
    
    
    if(pos.y-74 > threshold){
        w = ofMap(pos.y, threshold, ofGetWindowHeight(), 150, 300);
        h=ofMap(w, 500, 100, 120, 220);
    }
    
    if(pos.y-75 <= threshold){
        h = ofMap(abs(vel), 0, 5, 150, 170);
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    

    ofSetColor(255, 0, 0);
    ofEllipse(pos, w,h);
    
    ofSetColor(200,200,200);
    ofEllipse(pos, w-100,h-100);

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
