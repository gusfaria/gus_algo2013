#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0, 0, 0);
    ofSetCircleResolution(100);
    ofEnableAlphaBlending();
    
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
    
    //particle
    for (int i = 0; i < 5; i++){
        addParticle();
    }
    
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
    for (int i = 0; i < particleList.size(); i++){
        particleList[i].resetForces();
        particleList[i].addForce(ofVec2f( sin(ofGetElapsedTimef()*3)*0.02, -0.1 ));
        particleList[i].addDampingForce();
        particleList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofEllipse(ofGetWindowWidth() *0.5, ofGetWindowHeight() * 0.5, radiusX, radiusX);
    
    //particles
    ofSetColor(255);
    for (int i=0; i < particleList.size(); i++){
        particleList[i].draw();
    }
    
    ofDrawBitmapStringHighlight(ofToString(particleList.size()), 10,10);

}
//--------------------------------------------------------------
void testApp:: addParticle(){
    Particle myParticle;
    float vel = sin(ofGetElapsedTimef());
    myParticle.setParams(mouseX, mouseY, vel, vel * 3);
    particleList.push_back(myParticle);
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
    //    float vel = sin(ofGetElapsedTimef() * 3);
    //    myParticle.setParams(x, y, vel, vel * -3);
    
    for (int i = 0; i < particleList.size(); i++){
        float circVal = ofRandom(PI);
        float vx = cos( circVal ) * ofRandom(0,4) * i;
        float vy = sin( circVal ) * ofRandom(0,4) * i;
        //        float vx = ofRandom(0,4);
        //        float vy = ofRandom(0,4);
		particleList[i].setParams(mouseX,mouseY,vx, vy);
        
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
