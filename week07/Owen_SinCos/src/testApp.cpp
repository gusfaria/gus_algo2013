#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    ofSetBackgroundAuto(false);
//    ofBackgroundGradient(ofColor(33,121,209,90), ofColor(50, 0, 0,90), OF_GRADIENT_CIRCULAR);
    ofEnableAlphaBlending();
    
    gui = new ofxUICanvas(10, 10, 230, 230);
    gui->addLabel("Controls");
    gui->addSpacer();
    gui->addSlider("Sin Modification", 0, 25, 10);
    gui->addSlider("Cos Modification", 0, 25, 10);
    gui->addSlider("Amplitude", 1, 50, 10);
    gui->addSlider("Particle Size", 1, 30, 10);
    gui->addSpacer();
    gui->addButton("Reset", false);
    gui->addSpacer();
    gui->addLabel("Press 'A' to add particles");
    gui->setColorBack(50);
    
    ofAddListener( gui->newGUIEvent, this, &testApp::onGuiEvent) ;
    
    sinChange = 10.0;
    cosChange = 10.0;
    velX = 10.0;
    pDiameter = 10.0;
    
    snapCounter = 0;
	bSnapshot = false;
	memset(snapString, 0, 255);
    

}

void testApp::exit() {
    delete gui;
}

void testApp::onGuiEvent( ofxUIEventArgs &e ) {
    
    if ( e.getName() == "Sin Modification" ) {
        ofxUISlider *sin = (ofxUISlider*)e.widget;
        sinChange = sin->getScaledValue();
    }
    
    if ( e.getName() == "Cos Modification" ) {
        ofxUISlider *cos = (ofxUISlider*)e.widget;
        cosChange = cos->getScaledValue();
    }
    
    if ( e.getName() == "Amplitude" ) {
        ofxUISlider *vel = (ofxUISlider*)e.widget;
        velX = vel->getScaledValue();
    }
    
    if (e.getName() == "Particle Size" ) {
        ofxUISlider *size = (ofxUISlider*)e.widget;
        pDiameter = size->getScaledValue();
    }
    
    if (e.getName() == "Reset" ) {
        ofxUIButton *r = (ofxUIButton*)e.widget;
        reset = r->getValue();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for ( vector<Particle>::iterator it = pList.begin(); it!=pList.end(); it++) {
        it->update( sinChange, cosChange, velX, pDiameter );
    }
    
    if (reset) {
        for ( vector<Particle>::iterator it = pList.begin(); it != pList.end(); ) {
            pList.erase(it);
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
//    ofBackgroundGradient(ofColor(33,121,209,10), ofColor(50,0,0,10), OF_GRADIENT_CIRCULAR);
    
    ofSetColor(0, 0, 0,10);
    ofRect(0,0, ofGetWindowWidth(), ofGetWindowHeight());
    
    for (vector<Particle>::iterator it = pList.begin(); it!=pList.end(); it++) {
        it->draw();
    }
    
    if (bSnapshot == true){
		// grab a rectangle at 200,200, width and height of 300,180
		img.grabScreen(0,0,ofGetWindowWidth(),ofGetWindowHeight());
        
		string fileName = "snapshot_"+ofToString(10000+snapCounter)+".png";
		img.saveImage(fileName);
		sprintf(snapString, "saved %s", fileName.c_str());
		snapCounter++;
		bSnapshot = false;
	}


}


//--------------------------------------------------------------
void testApp::createParticle(){
    Particle tmp( sinChange, cosChange, velX, pDiameter );
    pList.push_back( tmp );
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if ( key == 'a' || key == 'A' ) {
        createParticle();
    }
    
    if (key == 'x'){
		bSnapshot = true;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){


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