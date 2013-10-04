#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    
    // color button
    // quantity slider
    // size slider
    
    gui = new ofxUICanvas;
    gui->addLabel("Controls:");
    gui->addSpacer();
    gui->addButton("Random color", false, 20, 20);
    
    gui->setColorBack(ofColor(255,100));
    gui->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(255,100));
    gui->addSlider("size", 10, 40, 20);
    
    gui->setColorBack(ofColor(255,100));
    gui->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(255,100));
    gui->addSlider("quantity", 1, 100, 20);
    
    ofAddListener(gui->newGUIEvent,this,&testApp::onGuiEvent);
    
    gui -> loadSettings("guiSetting.xml");
    
    
    //particles
    ofSeedRandom();
    pSize = 30;
    quantity = 5;
    
    for (int i = 0; i < quantity; i++){
        addParticle();
    }
}
//--------------------------------------------------------------
void testApp::exit(){
//    gui->saveSettings("guiSettings.xml");
    delete gui;
}

//--------------------------------------------------------------
void testApp::onGuiEvent(ofxUIEventArgs &e){
    
    string name = e.widget->getName();
	int kind = e.widget->getKind();
    if( name == "size" ){
        ofxUISlider *sizeSlider = (ofxUISlider *)e.widget;
        pSize = sizeSlider->getScaledValue();

        cout << "Got a message! " << name << " - " << endl;
    
    }else if( name == "quantity"){
        ofxUISlider *q = (ofxUISlider *)e.widget;
        quantity = q->getScaledValue();

        cout << "Got a message! " << name << " - " << endl;

    }else if( name == "Random color"){
        
        ofxUIButton *Color = (ofxUIButton *)e.widget;
        cout << "Got a message! " << endl;
        if (Color->getValue() == 0) {
            color.setHsb(ofRandom(255), 200, 240);
        } else {
            color.setHsb(255, 255, 255);
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
        
        if (particleList.size()>700) {
            particleList.erase(particleList.begin());
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){

    ofSetColor(color);
    for (int i=0; i < particleList.size(); i++){
        particleList[i].draw();
    
        
        if(particleList[i].pos.y < 0 + pSize/2){
            particleList[i].vel.y *= -0.2;
        }
        
        if(particleList[i].pos.x < 0 || particleList[i].pos.x > ofGetWindowWidth()){
            particleList[i].vel.x *= -0.5;
        }
    
    
    }
    
    
    
}

//--------------------------------------------------------------
void testApp:: addParticle(){
    Particle myParticle(pSize, color);
    
    float circVal = ofRandom(PI);
    float vx = cos( circVal ) * ofRandom(0,4);
    float vy = sin( circVal ) * ofRandom(0,4);
    
    myParticle.setParams(mouseX, mouseY, vx, vy);
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

    for (int i = 0; i < quantity; i++){
        addParticle();
        
	}
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
////    float vel = sin(ofGetElapsedTimef() * 3);
////    myParticle.setParams(x, y, vel, vel * -3);
//
//    for (int i = 0; i < quantity; i++){
////        float circVal = ofRandom(PI);
////        float vx = cos( circVal ) * ofRandom(0,4) * i;
////        float vy = sin( circVal ) * ofRandom(0,4) * i;
////		particleList[i].setParams(mouseX,mouseY,vx, vy);
//        
//        addParticle();
//        
//	}
    
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
