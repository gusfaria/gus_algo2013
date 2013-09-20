#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    bIsRecording = false;
    playBackStartTime = 0;
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    
}

//--------------------------------------------------------------
void testApp::draw(){

    
    //draw the line
//    ofSetColor(ofColor::lime);
//    ofNoFill();
//    ofBeginShape();{
//        for( vector<TimePoint>::iterator it = points.begin(); it != points.end(); it++){
//            ofVertex(it->x, it->y);
//        }
//    }ofEndShape();
    
    // draw the playback
    if(bIsRecording == false){
    ofPoint pos = getPositionForTime(ofGetElapsedTimef() - playBackStartTime);
    ofFill();
    ofSetColor(ofColor::orangeRed,50);
    ofCircle(pos.x, pos.y, 40);
    }
    ofSetColor(ofColor::limeGreen, 5);
        ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
}

//--------------------------------------------------------------
ofPoint testApp::getPositionForTime(float time){
    if (bIsRecording) {
        return ofPoint(0,0,0);
    } else if(points.size() < 2) {
        return ofPoint(0,0,0);
    }
    
    //normalize
    while (time > points[points.size()-1].t) {
        time -= points[points.size()-1].t;
    }
    
    ofPoint pos;
    
    for (int i = 0; i < points.size()-1; i++) {
        if (time >= points[i].t && time < points [i+1].t) {
            //calculate the percent
            float part = time - points[i].t;
            float whole = points[i+1].t - points[i].t;
            float pct = part/whole;
            
            pos.x = (1-pct) * points[i].x + pct * points[i+1].x;
            pos.y = (1-pct) * points[i].y + pct * points[i+1].y;
            
        }
    }
    
    return  pos;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    bIsRecording = false;
    playBackStartTime = ofGetElapsedTimef();

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    TimePoint temp;
    temp.x = x;
    temp.y = y;
    temp.t = ofGetElapsedTimef() - startTime;
    
    points.push_back(temp);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    points.clear();
    TimePoint temp;
    temp.x = x;
    temp.y = y;
    temp.t = 0;
    
    points.push_back(temp);
    startTime = ofGetElapsedTimef();
    
    
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
