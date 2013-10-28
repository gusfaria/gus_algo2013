#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSeedRandom();
//    ofSetBackgroundAuto(false);
    
    ofSetVerticalSync(true);
    ofBackground(0);

    dest.set(ofRandomWidth(),ofRandomHeight());
    pos = ofGetWindowSize() / 2;
    car.setParam( pos, ofVec2f(10, -5) );
}

//--------------------------------------------------------------
void testApp::update(){
    car.seek( dest );
    car.update();
    
    if( car.pos.distance(dest) < 5){ //where is the distance coming from???
        dest = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    car.draw();

    ofSetColor(ofColor::lime);
    ofCircle(dest, 10);



    

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
