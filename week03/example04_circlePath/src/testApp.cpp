#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    radius = 0.5;
}

//--------------------------------------------------------------
void testApp::update(){
    radius += 0.1;
}

//--------------------------------------------------------------
void testApp::draw(){
        
    
    float angle = ofGetElapsedTimef() * 3.5;
    float x = radius * cos( angle );
    float y = radius * sin( angle );
    
    ofPoint pos;
    pos.x = x;
    pos.y = y;
    pointList.push_back( pos );
    if( pointList.size() > 5000 ){
        pointList.erase( pointList.begin());
    }
    
    ofPushMatrix();{
        ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
        ofRotateZ(angle);
        ofNoFill();
        ofSetColor(255);
        ofBeginShape();{
            for (int i = 0; i < pointList.size(); i++) {
                    ofVertex(pointList[i]);
            }
        }ofEndShape();
        
        ofFill();
        ofSetColor(255,0,255);
        ofCircle(pos, 10);
        
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
