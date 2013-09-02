#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0);
    ofSetVerticalSync(TRUE);
    
    myRect.pos.x = ofGetWindowWidth();
	myRect.pos.y = ofGetWindowHeight();
	myRect.posa.x = 0;
	myRect.posa.y = ofGetWindowHeight()/2;
	myRect.posb.x = ofGetWindowWidth();
	myRect.posb.y = ofGetWindowHeight()/2;
    
    myRect.interpolate(0);


}

//--------------------------------------------------------------
void testApp::update(){
    
    pct += 0.03;
    if (pct> 1) {
        pct = 0;
    }
    
    myRect.interpolate(pct);
    myRect.update();
}
//--------------------------------------------------------------
void testApp::draw(){

    myRect.draw();

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
