#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetCircleResolution(100);
    ofSetBackgroundAuto(false);
    
    

}


//--------------------------------------------------------------
void testApp::update(){
    if (ofGetElapsedTimeMillis() % 10 == 0) {
        Bomb tmp;
        particleList.push_back( tmp );
    }
    
    
    for( vector<Particle>::iterator it = myParticle.begin(); it!=myParticle.end();){
        
        it->update();
        
        if ( it->bIsDied() ) {
            it = myParticle.erase(it);
        }
        else {
            it++;
        }
    }
    
    for ( int i = 0; i < particleList.size(); i++ ) {
        particleList[i].update();
        
        if (particleList[i].bExploded()) {
            for ( int k = 0; k < 100; k ++ ) {
                addParticle(particleList[i].pos, particleList[i].initVel, particleList[i].color.getHue());
            }
            
            particleList.erase(particleList.begin() + i);
        }
    }
    


}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0, 0, 0,10);
    ofRect(0,0,ofGetWindowWidth(), ofGetWindowHeight());
    ofDrawBitmapStringHighlight(ofToString(myParticle.size()), ofPoint(30,50));
    
    for( vector<Particle>::iterator it = myParticle.begin(); it!=myParticle.end(); it++){
        it->draw();
    }
    
    for( int i = 0; i > particleList.size(); i++){
        ofSetColor(255,0,0);
        particleList[i].draw();
    }
}


//--------------------------------------------------------------
void testApp::addParticle(ofVec2f pos, float velMult, float hue){

    Particle tmp;
    tmp.setup(pos, velMult, hue);
    myParticle.push_back( tmp );

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
    Bomb tmp;
    particleList.push_back( tmp );
    
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
