#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0, 0, 0);
    ofSetCircleResolution(100);
    
    
    radiusX = 50;
    radiusY = radiusX;
    
    gui = new ofxUICanvas(); //ask for memory!! you are allocating memoriy
    gui -> addLabel("My controls");
    gui -> addSpacer();
    gui -> addButton("myButton", false, 40, 40);
    gui -> addSlider("radius", 0, 100, 50);

    gui ->loadSettings("myGuiSettings.xml");
    
    ofAddListener(gui->newGUIEvent, this, &testApp::onGuiEvent);
    
    ofSetColor(ofColor::seaGreen);
}

//--------------------------------------------------------------
void testApp::exit(){
    gui -> saveSettings("myGuiSetting.xml");
    delete gui; // you are deallocating memory //the last thing that the app will do is to delete this!
}

//--------------------------------------------------------------
void testApp::onGuiEvent( ofxUIEventArgs &e ){
    
    cout << "I got a message " << e.getName() << endl;
    
    if( e.getName() == "radius"){
        ofxUISlider  *radiusSlider = (ofxUISlider*)e.widget;
    
        radiusX = radiusSlider -> getScaledValue();
    } else if (e.getName() == "myButton"){
        ofxUIButton *b = (ofxUIButton*) e.widget;
        b -> getValue();
        
        if(b){
            ofSetColor(ofColor::purple);
        }
    }
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    ofEllipse(ofGetWindowWidth() *0.5, ofGetWindowHeight() * 0.5, radiusX, radiusX);

    
    
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
