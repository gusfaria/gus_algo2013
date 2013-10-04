#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //pointers(*) and address (&) operators
    // referencing and dereference??? WTF...
    int tmp = 5;
    int *myPtr = &tmp;
    int val = *myPtr;
    cout << myPtr << " /mypointer/ " << *myPtr << endl;
    cout << &val << " /my value/ " << val << endl;
    
    tmp = 8;

    cout << myPtr << " /mypointer/ " << *myPtr << endl;
    cout << &val << " /my value/ " << val << endl;
    
    testFunction( tmp );
    
}
//--------------------------------------------------------------
void testApp::testFunction(int &input){
//    input = 9;
    
    int &internalPtr = input;
    cout << "\n interal pointer :: " << internalPtr << " interal pointer add :: " << &internalPtr << endl;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

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
