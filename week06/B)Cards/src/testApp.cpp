#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(0, 128, 1);
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < Solitaire.size(); i++) {
        Solitaire[i].update();

    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    for (int i = 0; i < Solitaire.size(); i++) {
            Solitaire[i].draw();

    }
   

    
    
}

//--------------------------------------------------------------
void testApp::createCard(){
    Cards tmp;
    pos = mousePos;
    mousePos.x = mouseX;
    mousePos.y = mouseY;
//    tmp.vel.x = ofRandom(-2,2);
//        Solitaire[i].vel.y = ofRandom(-3,3);

    tmp.setup(pos, ofVec2f(ofRandom(-10,10),ofRandom(-10,10)));
    Solitaire.push_back(tmp);
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
    
    mousePos.x = x;
    mousePos.y = y;
    
    createCard();
    
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
