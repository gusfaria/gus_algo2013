#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){  

    ofBackground(255);
    ofSetVerticalSync(true);
    color = (ofColor::gray);
    myVectorField.setup(ofGetWindowWidth(), ofGetWindowHeight(), 20);
    
    for(int i = 0; i < 10000; i++){
        Particle tmp;
        particleList.push_back( tmp );
        particleList[i].setParams(ofRandomWidth(), ofRandomHeight(), ofRandom(-1,1), ofRandom(-1,1));
    }
    
    

}

//--------------------------------------------------------------
void testApp::update(){
    if (bHide) {
        ofBackground(255);
    } else {
        ofBackground(0);
    }
    
    if(bPerlin){
        myVectorField.setPerlin();
    }
    
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].resetForce();
        particleList[i].addForce(myVectorField.getForceAtScreenPos(particleList[i].pos)*0.005);
        particleList[i].addDampingForce();
        particleList[i].update();
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0);
    myVectorField.draw();
    for (int i = 0; i < particleList.size(); i++) {
        ofSetColor(color);
        particleList[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'p') bPerlin =! bPerlin;
    
    if (key == 'm') bMouse =! bMouse;
    
    if(key == 'b') bHide =! bHide;

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    //this is bernardo's code!!!!!
    //https://github.com/bschorr/schorr_algo2013/tree/master/week_08/algo_week_08_01_vectorFieldParticle1
    
    if (bMouse) {
        ofVec2f dir = ofVec2f ( ofGetMouseX() - ofGetPreviousMouseX(), ofGetMouseY() - ofGetPreviousMouseY());
        myVectorField.addLinearForce(x, y, dir*0.05, 100);
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
