#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );
        
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    myField.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    myField.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if( key == '1'){
        myField.setRandom( 20.0 );
    }else if( key == '2' ){
        myField.setPerlin();
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
    
    
    if( button == OF_MOUSE_BUTTON_1 ){
//        myField.addRepelForce(x, y, 100, 2.0);
        myField.addCircularForce(x, y, 300, 2.0);
    }else{
        myField.addAttractForce(x, y, 100, 2.0);
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    mouseDragged(x, y, button);
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
