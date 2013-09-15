#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetCircleResolution(100);
    ofSetVerticalSync(true);
    ofBackground(0);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofNoFill();
    ofSetColor(255);
    ofBeginShape();{
        for (int i = 0; i < pointList.size(); i++) {
            float angle = sin(ofGetElapsedTimef()*3.4);
            pointList[i].x += angle;
            pointList[i].z += 6;
            ofVertex(pointList[i]);
        }
        
    }ofEndShape();

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
    
    ofPoint tempPt;
    tempPt.x = x;
    tempPt.y = y;
    
    pointList.push_back( tempPt );
    
    if (pointList.size() > 100) {
        pointList.erase(pointList.begin()); //iterator
    }
    
    
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
