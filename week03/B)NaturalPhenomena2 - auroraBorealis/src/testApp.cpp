#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
//    ofBackground(0);
    ofEnableAlphaBlending();
    
    angle		= 0;
	angleAdder	= 0.1;
    ofBackground(0);
    ofSetBackgroundAuto(false);
    velX = 0.2;
}

//--------------------------------------------------------------
void testApp::update(){

    pos.x+=velX*2;
}


//--------------------------------------------------------------
void testApp::draw(){
    
    float mappedPosY = cos(ofGetElapsedTimef()*10);
    pos.y = ofMap(mappedPosY, -1, 1, 0, ofGetWindowHeight());
    
//    float mappedPosX = sin(ofGetElapsedTimef())/5;
//    pos.x = ofMap(mappedPosX, -1, 1, 0, ofGetWindowWidth());
    
    
    if(pos.x >= ofGetWindowWidth()-10) {
        velX *= -1;
    }
    
    ofSetColor(200, 0, 200, 70);
    ofCircle(pos.x, pos.y, 10);
    
}

void testApp::wave(float vel, float angleBase,int amp, int rectW, int rectH)
{
//    ofPushMatrix();{
//        
//        float angle = vel;
//        float radius = 10;
//        
//        float x = radius * cos(angle)*10;
//        float y = radius * sin(angle)*40;
//        
//        ofPoint temp;
//        temp.x = x;
//        temp.y = y;
//        pointList.push_back(temp);
//        if( pointList.size() > 50 ){
//            pointList.erase( pointList.begin());
//        }
//        ofTranslate(ofRandom(0,ofGetWindowWidth()), ofGetWindowHeight()/2);
//        ofRotateX(angle);
//
//        for (int i = 0; i< pointList.size(); i++){
//            ofRotateZ(ofGetElapsedTimef()*sin(1));
//            ofRect(i*10, 0 + sin(angleBase + angle + angleAdder*i) * amp, rectW, rectH);
//            
//            
//        }
//    }ofPopMatrix();
    
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
//    ofPoint tempPt;
//    tempPt.x = x;
//    tempPt.y = y;
//    
//    pointList.push_back( tempPt );
//    
//    if (pointList.size() > 500) {
//        pointList.erase(pointList.begin());
//    }

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
