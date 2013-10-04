#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);

    for (int i =0; i<100; i++) {
        Particle p;
        p.mass = ofRandom(0.2,0.3);
        particleList.push_back(p);
    }

    ofBackground(0);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
    
    ofVec2f gravity (0.0, 0.1);
    ofVec2f wind (0.1, 0.0);
    
    for (int i=0; i<particleList.size(); i++) {
        particleList[i].applyForce( gravity * particleList[i].mass);
        particleList[i].applyForce( wind );
        
        particleList[i].update();
    }
    

}

//--------------------------------------------------------------
void testApp::draw(){
    for (int i=0; i<particleList.size(); i++) {
        particleList[i].draw();
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
