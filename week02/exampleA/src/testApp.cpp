#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(FALSE);
    
    for(int i = 0; i <20; i++){
        Rectangle tmpRect;
        rectlist.push_back(tmpRect); //put the tmpRect inside the vector (rectlist)
    }

}

//--------------------------------------------------------------
void testApp::update(){

    for(int i = 0; i<rectlist.size(); i ++){
        if (i == 0) rectlist[i].xenoToPoint(mousePos.x, mousePos.y);
        else rectlist[i].xenoToPoint(rectlist[i-1].pos.x, rectlist[i-1].pos.y);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
//    ofBackground(100,100, 100, 255 * 0.1);

    ofPushMatrix();
        ofColor semiTransparent (100,100,100, 255.0*0.1);
        ofSetColor(semiTransparent);
        ofSetRectMode(OF_RECTMODE_CORNER);
        ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    ofPopMatrix();
    
    for(int i = 0; i<rectlist.size(); i ++){
        rectlist[i].draw();
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
    mousePos.x = x;
    mousePos.y = y;
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
