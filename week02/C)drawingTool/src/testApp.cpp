#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetCircleResolution(60);
    ofSetBackgroundAuto(false);    
    ofSetRectMode(OF_RECTMODE_CENTER);

}

//--------------------------------------------------------------
void testApp::update(){

    

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(0,0,0,90);
    ofPushMatrix();{
        
        for (int i = 0; i < myElements.size(); i++) {
            myElements[i].draw();
            
        }
        
//        float angle = sin(ofGetElapsedTimef()*0.5);
//        element.z += angle;
//        ofRotate(element.z, mouseX, mouseY,0);
//        ofNoFill();
//        ofSetColor(255);
//        element.x += 6;
//        element.y += 3;
//        ofRect(mouseX, mouseY, element.x, element.y);
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
    Element newElement;
    newElement.setup(mousePos);
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
