#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(100);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    circlePos = -20;
    circleVel = 30;
    circleDislocation = 0;
    circleBeat = 0;
    
    rectPos = -300;
    rectVel = 30;
    rectBeat = 0;
    rectSize = 60;
    
    rectanglesPos = 0;
    rectanglesVel = 30;
    rectanglesBeat = 0;

}

//--------------------------------------------------------------
void testApp::update(){
//circle
    circlePos += circleVel;
    if(circlePos == 100){
        circlePos = 100;
        circleVel = 0;
        circleBeat = cos(ofGetElapsedTimef() * 15);
        circleDislocation = ofMap(circleBeat, -1, 1, 0, -60);
    }
//square
    rectPos += rectVel;
    if(rectPos == 300){
        rectVel = 0;
        rectanglesPos = 300;
        rectBeat = sin(ofGetElapsedTimef() * 20);
        rectSize = ofMap( rectBeat, -1, 1, 40, 60);
    }
    
//rectangles
    rectanglesPos += rectanglesVel;
    if (rectanglesPos == -100) {
        rectanglesVel = -100;
        rectanglesPos = 0;
        rectanglesBeat = sin(ofGetElapsedTimef() * 17);
        rectangleAnimation = ofMap( rectBeat, -1, 1, rectanglesPos-22, -92);
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
//    
//    float  beat = sin(ofGetElapsedTimef() * 20);
//    float mySize = ofMap( beat, -1, 1, 40, 60);
    
    //circle
    ofSetColor(111,60,116);
    ofCircle(circlePos, ofGetWindowHeight()/2+circleDislocation, 50);
    
    //square
    ofSetColor(211, 56, 148);
//    ofRect(ofGetWindowWidth()*3/4, ofGetWindowHeight()/2, mySize*2, mySize*2);
    ofRect(rectPos, ofGetWindowHeight()/2, rectSize*2, rectSize*2);
    
    
//retangulos
//    ofPushMatrix();{
//    ofSetColor(124, 54, 124);
////        float  rectBeat = sin(ofGetElapsedTimef() * 17);
////        float rectAnim = ofMap( rectBeat, -1, 1, 90, 160);
////        float rectAnim2 = ofMap( rectBeat, -1, 1, 30, 15);
////        float rectAnim3 = ofMap( rectBeat, -1, 1, 105, 120);
//        ofTranslate(rectanglesPos, 0);
//        ofRect(rectangleAnimation, ofGetWindowHeight()/2, 15, 90);
//        ofRect(rectanglesPos, ofGetWindowHeight()/2, 15, 90);
//        ofRect(rectanglesPos+22, ofGetWindowHeight()/2, 15, 90);
//        ofRect(rectanglesPos+44, ofGetWindowHeight()/2, 15, 90);
//        
////        ofRect(rectAnim2, ofGetWindowHeight()/2, 15, 90);
////        ofRect(55, ofGetWindowHeight()/2, 15, rectAnim);
////        ofRect(80, ofGetWindowHeight()/2, 15, rectAnim);
////        ofRect(rectAnim3, ofGetWindowHeight()/2, 15, 90);
//    }ofPopMatrix();

    
    //retangulos
    ofPushMatrix();{
        ofTranslate(400, 0);
        ofSetColor(124, 54, 124);
    float  rectBeat = sin(ofGetElapsedTimef() * 17);
    float rectAnim = ofMap( rectBeat, -1, 1, 90, 160);
    float rectAnim2 = ofMap( rectBeat, -1, 1, 30, 15);
    float rectAnim3 = ofMap( rectBeat, -1, 1, 105, 120);
    ofRect(rectAnim2, ofGetWindowHeight()/2, 15, 90);
    ofRect(55, ofGetWindowHeight()/2, 15, rectAnim);
    ofRect(80, ofGetWindowHeight()/2, 15, rectAnim);
    ofRect(rectAnim3, ofGetWindowHeight()/2, 15, 90);
    }ofPopMatrix();
    
    
//triangulo
    ofSetColor(252, 43, 145);

    
    

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
