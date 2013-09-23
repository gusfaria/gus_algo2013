#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
//    ofBackground(0,0,0,5);

    ofSetColor(100,255,10,20);
    
    ofPushMatrix();{
        ofTranslate( ofGetWindowSize() / 2);

        
        ofBeginShape();
        for (int i = 0; i < 100; i++){
            
            float add = ofNoise(sin((i/100.0)*TWO_PI), ofGetElapsedTimef());  // symetrical because of the use of sin
            
            // we're passing in 2 dimentions here. One is where we are on the circle
            // and the other is a combination of elapsed time and our mouse position. 2D Noise!
//            float add = ofNoise(i/20.0f, ofGetElapsedTimef() * 3 * (float)mouseX / (float)ofGetWidth());
            
            // this will draw a circle with a min radius of 200, and a max of 300
            ofVertex( (200 + 100 * add) * cos((i/100.0)*TWO_PI),
                      (200 + 10 * add) * sin((i/100.0)*TWO_PI));
        }
        ofEndShape();
            
    }ofPopMatrix();
    
    ofSetColor(0, 0, 0,10);
    ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
//    float posX = sin(ofGetElapsedTimef() *  ofRandom(3,1));
//    float positionX = ofMap(posX, -1, 1, 100, 300);
//    
//    ofSetColor(0, 0, 255,5);
//        ofCircle(positionX, mouseY, 20);
//        ofCircle(positionX, mouseY, 22);
//        ofCircle(positionX, mouseY, 24);
//        ofCircle(positionX, mouseY, 26);
//        ofCircle(positionX, mouseY, 28);
//    ofCircle(positionX, mouseY, 30);
    
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
