#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    
    ofEnableDepthTest();
    
    flocker.addParticle( 500 );
    
    myCam.setDistance(400);
}

//--------------------------------------------------------------
void testApp::update(){
    flocker.applyForces(80, 0.4, 0.75, 0.02, 0.1, 0.7);
    flocker.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    myCam.begin();
    
    flocker.draw();
    
    myCam.end();
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
