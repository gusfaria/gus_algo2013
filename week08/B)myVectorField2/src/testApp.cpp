#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){  

    ofBackground(255);
    ofSetVerticalSync(true);
    color.setHsb(0, 255, 255);
    
    myVectorField.setup(ofGetWindowWidth(), ofGetWindowHeight(), 20);
    
    for(int i = 0; i < 50000; i++){
        Particle tmp;
        particleList.push_back( tmp );
        particleList[i].setParams(ofRandomWidth(), ofRandomHeight(), ofRandom(-1,1), ofRandom(-1,1));
    }
    
    img.loadImage("img.jpg");
    img2.loadImage("img2.jpg");

}

//--------------------------------------------------------------
void testApp::update(){
    if (bHide) {
        ofBackground(255);
    } else {
        ofBackground(0);
    }
    
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].resetForce();
        particleList[i].addForce(myVectorField.getForceAtScreenPos(particleList[i].pos)*0.003);
        particleList[i].addDampingForce();
        particleList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){

    myVectorField.draw();
    for (int i = 0; i < particleList.size(); i++) {
        ofSetColor(color);
        particleList[i].draw();
    }
    
    ofDrawBitmapStringHighlight("Press p for Perlin", 10,10);
    ofDrawBitmapStringHighlight("Press r for random Perlin", 10,25);
    ofDrawBitmapStringHighlight("Press m for Mouse interference", 10,40);
    ofDrawBitmapStringHighlight("Press b to see the vector field", 10,55);
    ofDrawBitmapStringHighlight("Press i for img vector field", 10,70);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
//    if(key == 'p') bPerlin =! bPerlin;
//    if(key == 'r') bSetPerlin =! bSetPerlin;
    
    if(key =='p'){
        myVectorField.setPerlin();
    }
    
    if(key =='r'){
        myVectorField.setPerlin( ofRandom(0.01, 0.09));
    }
    
    if (key == 'm') bMouse =! bMouse;
    if(key == 'b') bHide =! bHide;
    
    
    if(key =='i'){
        myVectorField.useImage(img);
    }
    
    if(key =='u'){
        myVectorField.useImage(img2);
    }

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
