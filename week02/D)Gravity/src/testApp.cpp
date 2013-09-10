#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(60);
    ofSetVerticalSync(true);
//    gravity = 0.98f;
    earthGravity = 9.8;
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
        myElements[i].draw();
        
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    // change color of each one based on their gravity ???
    
    if (key == 'e') {
        gravity = earthGravity;
        color = ofColor(0,0,255);
    } else if (key == 'j'){
        gravity = 2.48*earthGravity;
        color = ofColor(255,0,0);
    } else if (key == 'm'){
        color = ofColor(255);
        gravity = earthGravity/6;
    } else {
        gravity = earthGravity/6;
    }
    
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
    newElement.setup(mousePos, gravity, color);
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
