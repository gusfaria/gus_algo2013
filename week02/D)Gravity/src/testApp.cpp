#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(60);
    ofSetVerticalSync(true);
    gravity = 0.98f;
    
    ofSeedRandom();
    color = ofRandom(0,255);

}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < myElements.size(); i++) {
        myElements[i].update();
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    mousePos.set(mouseX,mouseY);
    for (int i = 0; i < myElements.size(); i++) {
        ofSetColor(color);
        myElements[i].draw();
    }
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
    Element newElement;
    newElement.setup(mousePos, gravity);
    myElements.push_back(newElement);
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
