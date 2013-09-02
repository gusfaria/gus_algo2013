#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofBackground(30,30,30);
    
    myRectangle.pos.x = 0;
    myRectangle.pos.y = 0;
	myRectangle.posa.x = 0;
    myRectangle.posa.y = 0;
    myRectangle.posb.x = ofGetWindowWidth();
    myRectangle.posb.y = ofGetWindowHeight();

    pct = 0;
    

}

//--------------------------------------------------------------
void testApp::update(){
	
    pct += 0.001;
	if (pct > 1) pct = 0;
    myRectangle.interpolate(pct);

}


//--------------------------------------------------------------
void testApp::draw(){
	myRectangle.draw();
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
        myRectangle.posa.x = x;
        myRectangle.posa.y = y;
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
