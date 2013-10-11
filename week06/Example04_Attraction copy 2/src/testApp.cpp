#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
//    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    
    
    for (int i=0; i<500; i++) {
        Particle p;
        
        
//        
//        ofVec2f newPos( ofRandomWidth(), ofRandomHeight());
//        p.pos = newPos;
        
        
            float x = ofMap(i,0,1500, 0,ofGetWidth());
        float y = ofMap(i, 0, 1500, 0, ofGetHeight());
            p.pos.x = i+x;
            p.pos.y = i+y;
            
        
        
//        p.pos.x = ofGetWindowWidth()/2;
//        p.pos.y = ofGetWindowHeight()/2;

        
        particleList.push_back(p);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i<particleList.size(); i++) {
        particleList[i].addAttractionForce(mouseX, mouseY, 1000, 0.1);
        particleList[i].addRepulsionForce(mouseX, mouseY, 100, 0.5);
        particleList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
        ofSetColor(0, 0, 0, 10);
        ofRect(0,0,ofGetWindowWidth(),ofGetWindowHeight());
        
        for (int i = 0; i<particleList.size(); i++) {
    //        ofColor color;
    //        color.setHsb(ofRandom(255), 250, 250);
    //        ofSetColor(color);

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
