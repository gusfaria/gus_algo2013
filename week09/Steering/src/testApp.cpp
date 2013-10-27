#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    dest = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    
    car.pos = ofGetWindowSize()/2;
    car.vel = ofVec2f(10,-5);
    
    car2.pos.x = ofRandomWidth();
    car2.pos.y = ofRandomHeight();
    car2.vel = ofVec2f(5,-10);

    ofBackground(100);
}

//--------------------------------------------------------------
void testApp::update(){
    car.seek(dest);
    car.update();
    if (car.pos.distance(dest) < 5) {
        dest = ofVec2f(ofRandomWidth(), ofRandomHeight());
    }
    
    car2.seek(dest);
    car2.update();
    if (car2.pos.distance(dest) < 5) {
        dest = ofVec2f(ofRandomWidth(), ofRandomHeight());
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255, 0, 0);
    car.draw();
    
    ofSetColor(0,0, 255);
    car2.draw();
    
    ofSetColor(0, 255, 0);
    ofCircle(dest, 4);

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
