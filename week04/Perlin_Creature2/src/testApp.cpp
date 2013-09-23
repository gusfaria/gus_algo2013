

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofBackground(0, 0, 0);
    ofSetCircleResolution(100);
    
    Eye.pos = ofPoint( ofGetWindowWidth()/2, ofGetWindowHeight() /2 - 40 );

}

//--------------------------------------------------------------
void testApp::update(){
    ofPoint mousePos( mouseX, mouseY );
    Eye.mousePos = mousePos;

}

//--------------------------------------------------------------
void testApp::draw(){

    ofSetColor(100,255,10,20);
    
    ofPushMatrix();{
        ofTranslate( ofGetWindowSize() / 2);

        
        ofBeginShape();
        for (int i = 0; i < 100; i++){
            
            float add = ofNoise(sin((i/100.0)*TWO_PI), ofGetElapsedTimef());
            
            ofVertex( (200 + 100 * add) * cos((i/100.0)*TWO_PI),
                      (200 + 10 * add) * sin((i/100.0)*TWO_PI));
        }
        ofEndShape();
        

        
    }ofPopMatrix();
    
    ofSetColor(0, 0, 0,10);
    ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    ofSetColor(255, 0, 0);
    Eye.draw();
    
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
