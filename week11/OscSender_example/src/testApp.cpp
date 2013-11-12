#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    mSender.setup("Localhost", 12345); //127.0.0.1 my localhost
    ofBackground(0);
    
    pos.set(ofGetWindowSize()/2);
    vel.set(10,0);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    pos+=vel;
    
    if(pos.x < 0 || pos.x > ofGetWindowWidth() ){
        vel.x *= -1;
    }
    
    if(pos.y < 0 || pos.y > ofGetWindowHeight() ){
        vel.y *= -1;
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(ofColor::seaGreen);
    ofCircle(pos, 30);
    
    ofSetColor(ofColor::pink);
    ofCircle(mousePos, 30);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    mousePos.set(x,y);
    
    ofxOscMessage m;
    m.setAddress("/mouse/pos"); //something unique and descriptive!
    m.addIntArg(mousePos.x); // we dont need 64 because is
    m.addIntArg(mousePos.y);
    mSender.sendMessage( m );
    
    ofxOscMessage m2;
    m2.setAddress("/ball/pos"); //something unique and descriptive!
    m2.addFloatArg ( pos.x ); // we dont need 64 because is
    m2.addFloatArg ( pos.y );
    mSender.sendMessage( m2 );
    
    
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
