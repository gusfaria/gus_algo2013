#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
	ofBackground(0);
    ofSetCircleResolution(100);
    ofEnableAlphaBlending();
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < 20; i++) {
        myElements[i].zenoToPoint(0.005*i, mouseX);
    }

}

//--------------------------------------------------------------
void testApp::draw(){

    for (int i=0; i < 20; i++) {
        myElements[i].draw(100*i, 5*i, 50*i, 50*i);
    }
//        myElement.draw(255,0,0);
//        myElement.draw(0,255,0);
//        myElement.draw(0,0,255);
    
    
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
