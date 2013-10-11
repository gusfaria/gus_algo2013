#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
//    ofBackground(0);
    
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofSetCircleResolution(60);
    
    for (int i=0; i<800; i++) {
        Particle p;
        
        ofVec2f newPos( ofRandomWidth(), ofRandomHeight());
        p.pos = newPos;

        particleList.push_back(p);
    }
    
    for (int k=0; k<800; k++) {
        Particle2 p2;
        
        ofVec2f newPos2( ofRandomWidth(), ofRandomHeight());
        p2.pos = newPos2;
        
        
        particleListPart2.push_back(p2);
    }
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i<particleList.size(); i++) {
        particleList[i].addAttractionForce(mouseX, mouseY, 1000, 0.1);
        particleList[i].addRepulsionForce(mouseX, mouseY, 100, 0.5);
        particleList[i].update();
    }
    
    for (int k = 0; k<particleListPart2.size(); k++) {
        particleListPart2[k].addAttractionForcePart2(mouseX, mouseY,1000, 0.4);
        particleListPart2[k].addRepulsionForcePart2(mouseX, mouseY, 100, 0.7);
        particleListPart2[k].update();
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
//    
//        ofSetColor(0, 0, 0, 10);
//        ofRect(0,0,ofGetWindowWidth(),ofGetWindowHeight());
//    ofBackground(0, 0, 0, 10);
    ofBackgroundGradient(ofColor(33,121,209,10), ofColor(50, 0, 0,10), OF_GRADIENT_CIRCULAR);
    
        for (int i = 0; i<particleList.size(); i++) {
            particleList[i].draw();
        }
    
    
        for (int k = 0; k<particleListPart2.size(); k++) {
            ofSetColor(0, 255, 0);
            particleListPart2[k].draw();
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
