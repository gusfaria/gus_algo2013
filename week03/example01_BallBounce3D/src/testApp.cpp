#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    ofSetCircleResolution(60);
    ofEnableAlphaBlending();
    
    boxRadius = 200;
    
    ballPos = ofPoint(0.0, 0.0, 0.0);
    ballVel =ofVec3f(ofRandomf(), ofRandomf(), ofRandomf());
    
    ballVel *= 5.0;
    
    mBox = ofBoxPrimitive(boxRadius*2, boxRadius*2, boxRadius*2);
    
    angle = 1;
}

//--------------------------------------------------------------
void testApp::update(){
    ballPos += ballVel;
    
    if (ballPos.x > boxRadius || ballPos.x < -boxRadius) {
        ballVel.x *= -1;
    }
    if (ballPos.y > boxRadius || ballPos.y < -boxRadius) {
        ballVel.y *= -1;
    }
    if (ballPos.z > boxRadius || ballPos.z < -boxRadius) {
        ballVel.z *= -1;
    }
    
    
    rotation += angle;
    
}

//--------------------------------------------------------------
void testApp::draw(){


    ofPushMatrix();{
        ofSetColor(255, 255, 255, 255);
        ofTranslate(ofGetWindowSize()/2.0);
        ofRotate(rotation, 0, 0, rotation);
//        ofCircle(ballPos, 20);
        ofDrawSphere(ballPos, 20);
        ofSetColor(255,255,255,255*0.2);
        mBox.getMesh().drawWireframe(); //OpenGl stuff ... A mesh is a collection of vertixes! A buffer is a list of Array! 
    } ofPopMatrix();

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
