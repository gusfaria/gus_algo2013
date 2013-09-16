#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
//    ofBackground(0);
    ofEnableAlphaBlending();
    
    angle		= 0;
	angleAdder	= 0.1;
    


}

//--------------------------------------------------------------
void testApp::update(){

    	angle+=angleAdder;

    
}


//--------------------------------------------------------------
void testApp::draw(){
    ofBackgroundGradient(ofColor(10,40,80), ofColor(0, 0, 0), OF_GRADIENT_LINEAR);


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

    buffer[0].draw(0, 0, 1024, 768);


    
    

    ofFill();
    ofSetColor(ofColor::lime,30);
    wave(0,30,64,300);
    ofSetColor(ofColor::cadetBlue,40);
    wave(40,30,30,100);

}

void testApp::wave(float angleBase,int amp, int rectW, int rectH)
{
    ofPushMatrix();{
        float angle = ofGetElapsedTimef()   * 1.2;
        float radius = 200;
        
        float x = radius * cos(angle);
        float y = radius * sin( angle);
        
        ofPoint temp;
        temp.x = x;
        temp.y = y;
        pointList.push_back(temp);
        if( pointList.size() > 100 ){
            pointList.erase( pointList.begin());
        }
        ofTranslate(0, ofGetWindowHeight()/2);
        ofRotateX(angle);
        for (int i = 0; i< pointList.size(); i++){
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
