#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetCircleResolution(60);
    ofSetVerticalSync(true);
//    gravity = 0.98f;
    earthGravity = 9.8;
    ofSeedRandom();

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
    
    ofDrawBitmapString("ACTUAL GRAVITY : " + ofToString(gravity), ofPoint(10,15));
    ofDrawBitmapString("PRESS E FOR EARTH'S GRAVITY", ofPoint(10,30));
    ofDrawBitmapString("PRESS M FOR MOON'S GRAVITY", ofPoint(10,45));
    ofDrawBitmapString("PRESS J FOR JUPITER'S GRAVITY", ofPoint(10,60));
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    // change color of each one based on their gravity ???
    
//    if (key == 'e') {
//        gravity = earthGravity;
//        color = (0,0,255);
//    } else if (key == 'j'){
//        color = (255,0,0);
//        gravity = 2.48*earthGravity;
//    } else if (key == 'm'){
//        color = (255);
//        gravity = earthGravity/6;
//    } else {
//        gravity = earthGravity/6;
//    }
    
    
    switch (key) {
        case 'e':
            gravity = earthGravity;
            ofSetColor(255, 0, 0);
            break;
        case 'j':
            gravity = 2.48*earthGravity;
            break;
        case 'm':
            gravity = earthGravity/6;
            break;
        default:
            break;
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
