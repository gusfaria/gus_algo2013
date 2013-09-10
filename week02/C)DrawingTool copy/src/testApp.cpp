#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
//    ofBackground(0);
    ofEnableSmoothing();
    ofSetCircleResolution(60);
    ofSetBackgroundAuto(false);    
    ofSetRectMode(OF_RECTMODE_CENTER);

}

//--------------------------------------------------------------
void testApp::update(){

    for( int i=0; i<myElements.size(); i++ ){
        myElements[i].mousePos.x = mouseX;
        myElements[i].mousePos.y = mouseY;
        myElements[i].update();
    }

    
}

//--------------------------------------------------------------
void testApp::draw(){
        ofPushMatrix();{
        
    ofBackground(0,80);        
        for (int i = 0; i < myElements.size(); i++) {
            ofSetColor(255);
//            float angle = sin(ofGetElapsedTimef());
//            mousePos.x += angle;
//            ofRotate(mousePos.x);
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
    Element newElement;
    newElement.setup(mousePos);
    myElements.push_back(newElement);
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
