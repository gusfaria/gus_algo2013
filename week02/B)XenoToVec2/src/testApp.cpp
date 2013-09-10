#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetBackgroundAuto(false);
    wSize = 768;
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    
    mousePos.x = mouseX;
    mousePos.y = mouseY;
    for (int i = 0; i < myElements.size(); i++) {
        myElements[i].upload(ofRandom(0.01, 0.05), mousePos);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    

    
    for (int i = 0; i < myElements.size(); i++) {
        myElements[i].myColor = (0, 100, 255);
        myElements[i].draw();
    }
    
    ofPushMatrix();{
        ofSetRectMode(OF_RECTMODE_CORNER);
        ofSetColor(0, 0, 0, 10);
        ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
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
    Element tempElement;
    tempElement.setup(color);
    myElements.push_back(tempElement);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    for (int i = 0; i < myElements.size(); i++) {
        myElements.pop_back();
    }
    
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
