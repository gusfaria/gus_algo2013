#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
//    ofBackground(0);
    ofEnableAlphaBlending();
    
    angle		= 0;
	angleAdder	= 0.1;
    
    ofSetBackgroundAuto(false);

}

//--------------------------------------------------------------
void testApp::update(){

    	angle+=angleAdder;

    
}


//--------------------------------------------------------------
void testApp::draw(){


//    ofNoFill();
//    ofSetColor(255, 0, 0);
//    ofBeginShape();{
//        for (int i = 0; i < pointList.size(); i++) {
//            float angleSin = sin(ofGetElapsedTimef()*0.3);
//            float angleCos = cos(ofGetElapsedTimef() *0.5);
//            pointList[i].x += angleSin;
//            pointList[i].y += angleCos;
//            ofBlendMode();
//            ofVertex(pointList[i]);
//        }
//    }ofEndShape();
    
    
    ofSetColor(ofColor::cornflowerBlue, 20);
    wave(100,30,ofGetElapsedTimef()* 10,100,16);

    ofSetColor(ofColor::lime, 10);
    wave(120,30,ofGetElapsedTimef()* -1.3,10,100);
    
    ofBackgroundGradient(ofColor(5,10,50,5), ofColor(0, 0, 0,5), OF_GRADIENT_LINEAR);
}

void testApp::wave(float vel, float angleBase,int amp, int rectW, int rectH)
{
    ofPushMatrix();{
        
        float angle = vel;
        float radius = 10;
        
        float x = radius * cos(angle)*10;
        float y = radius * sin(angle)*40;
        
        ofPoint temp;
        temp.x = x;
        temp.y = y;
        pointList.push_back(temp);
        if( pointList.size() > 50 ){
            pointList.erase( pointList.begin());
        }
        ofTranslate(ofRandom(0,ofGetWindowWidth()), ofGetWindowHeight()/2);
        ofRotateX(angle);

        for (int i = 0; i< pointList.size(); i++){
            ofRotateZ(ofGetElapsedTimef()*sin(1));
            ofRect(i*10, 0 + sin(angleBase + angle + angleAdder*i) * amp, rectW, rectH);
            
            
        }
    }ofPopMatrix();
        
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
    ofPoint tempPt;
    tempPt.x = x;
    tempPt.y = y;
    
    pointList.push_back( tempPt );
    
    if (pointList.size() > 500) {
        pointList.erase(pointList.begin());
    }

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
