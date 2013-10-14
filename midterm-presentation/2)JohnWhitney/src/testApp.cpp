#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    pos = (ofGetWindowSize()/2);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    float mousePosX = mouseX;
    float mousePositionX = ofMap(mousePosX, 0, ofGetWindowWidth(), 0, 5);
    
    float mousePosY = mouseY;
    float mousePositionY = ofMap(mousePosY, 0, ofGetWindowHeight(), 0, 5);
    
    //make in a way that a camera goes towards the center of the twister...

    float angle = ofGetElapsedTimef()   * 0.5;
    float radius = 200;
    
    float x = radius * cos(angle * mousePositionX);
    float y = radius * sin( angle * mousePositionY);
    
    ofPoint temp;
    temp.x = x;
    temp.y = y;
    pointList.push_back(temp);
    if( pointList.size() > 40 ){
        pointList.erase( pointList.begin());
    }
        
    for (int i=0; i<pointList.size(); i++) {
        ofPushMatrix();{
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
            ofRotateZ(ofGetElapsedTimef() * -5.0*i);
            ofNoFill();
            ofSetColor(255*0.05*i,0,255,30);
            ofRect(x,y,30*i,30*i);
        }ofPopMatrix();
    }
    
        ofBackgroundGradient(ofColor(10,40,80,10), ofColor(255, 0, 50,10), OF_GRADIENT_CIRCULAR);
    
//    ofPushMatrix();{
//        ofSetRectMode(OF_RECTMODE_CORNER);
//        ofFill();
//        ofSetColor(0,1);
//        ofRect(0,0, ofGetWindowWidth(), ofGetWindowHeight());
//    } ofPopMatrix();
//    


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
