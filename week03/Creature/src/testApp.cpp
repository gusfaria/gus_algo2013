#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    
    ofSetCircleResolution(100);
    
//    leftEye.pos = ofPoint( ofGetWindowWidth()/2 - 20 , ofGetWindowHeight()/2);
//    rightEye.pos = ofPoint( ofGetWindowWidth()/2 + 20, ofGetWindowHeight()/2);


    
}

//--------------------------------------------------------------
void testApp::update(){
    ofPoint mousePos( mouseX, mouseY );
    
    leftEye.mousePos = mousePos;
    rightEye.mousePos = mousePos;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //hair
    ofSetColor(0, 200, 0);
    ofEllipse(position.x-50, position.y, 110, 100);
    ofEllipse(position.x-40, position.y-10, 90, 100);
    ofEllipse(position.x+50, position.y, 110, 100);
    ofEllipse(position.x+40, position.y-10, 90, 100);

    
    //head
    ofFill();
    ofSetColor(239,228,217);
    ofEllipse(position.x, position.y+20, 115, 150);
    
    leftEye.pos = ofPoint(position.x - 20 , position.y);
    rightEye.pos = ofPoint(position.x + 20 , position.y);
        
    leftEye.draw();
    rightEye.draw();

    //nose
    ofNoFill();
    ofEllipse(position.x, position.y + 30, 30, 30);
    ofFill();
    ofSetColor(ofColor::red);
    ofEllipse(position.x, position.y + 30, 30, 30);
    
//    //mouth
    ofSetColor(255, 0, 0);
    ofEllipse(position.x, position.y + 70, 50, mouseY*0.05);
    ofSetColor(0, 0, 0);
    ofEllipse(position.x, position.y + 70, 40, mouseY*0.04);
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
    position.x = x;
    position.y = y;
    
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
