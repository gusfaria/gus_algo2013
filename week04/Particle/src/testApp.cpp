#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetCircleResolution(100);

}


//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
        ofPoint pos;
//        pos.x = ofNoise (ofGetElapsedTimef()) * ofGetWindowWidth();
//        pos.y = ofNoise (ofGetElapsedTimef()) * ofGetWindowHeight();
//        ofCircle(pos, 10);
    
    ofPushMatrix();{
        ofTranslate(ofGetWindowSize() / 2);
        ofBeginShape();{

            for (int i = 0; i < 100; i++) {
                float add = ofNoise(i/20.f,ofGetElapsedTimef() * 3);
                ofSetColor (100);
                ofVertex((200+100*add) * cos((i/100.0)*TWO_PI), (200+100*add) * sin((i/100.0)*TWO_PI));
            }
            
        }ofEndShape();
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
