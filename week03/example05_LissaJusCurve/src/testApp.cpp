#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetCircleResolution(100);
    ofEnableSmoothing();

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    float angle = ofGetElapsedTimef()   * 3.5;
    float radius = 200;
    
    float x = radius * cos(angle * 3.4);
    float y = radius * sin( angle * 4.7);
    
    ofPoint temp;
    temp.x = x;
    temp.y = y;
    pointList.push_back(temp);
    if( pointList.size() > 400 ){
        pointList.erase( pointList.begin());
    }
    
    ofPushMatrix();{
        ofTranslate(ofGetWindowSize()/2);
        ofNoFill();
        ofSetColor(0, 255, 100);
        ofBeginShape();{
            for (int i = 0; i < pointList.size(); i++) {
                ofVertex(pointList[i]);
            }
        }ofEndShape();
    }ofPopMatrix();

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
