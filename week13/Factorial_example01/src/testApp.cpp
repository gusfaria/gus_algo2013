#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAlphaBlending();
    ofBackground(0);
    cout <<  "factorial " <<factorial(5) << endl;
}

//--------------------------------------------------------------
void testApp::update(){
    
    result = 5 * 4 * 3 * 2 * 1;
    cout <<  "result " << result << endl;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();{
        ofTranslate(ofGetWindowSize()/2);
        ofSetColor(ofColor::lightSkyBlue, 50);
        for(int i = 0; i < factorial(10); i++){
            ofRotate(i);
            ofRect(2*i + mouseX, 2*i + mouseY, i + 10, i + 10);
        }
    } ofPopMatrix();
}

//--------------------------------------------------------------
double testApp::factorial(double n){
    // recursive function //
    if(n == 0) {
        return 1;
    } else {
        return  (n * factorial (n-1));
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
