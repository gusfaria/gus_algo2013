#include "testApp.h"

using namespace ofxCv;

//--------------------------------------------------------------
void testApp::setup() {
    
    ofBackground( 251, 146, 64 );
	ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
	ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
    ofSetCircleResolution(60);
    
	cam.initGrabber(320, 240);
	
	tracker.setup();
    mouthRadius = 40;

    //particle
    for (int i = 0; i < 50; i++){
        Particles p;
        p.pos.set(ofRandomWidth(), ofRandomHeight());
        particleList.push_back(p);
    }
    
    //burger
    for (int i = 0; i < 5; i++){
        Burger b;
        b.pos.set(ofRandomWidth(), ofRandomHeight());
        burgerList.push_back(b);
    }
    
    

    //tracker movimentation
    fat = 0.01f;
    myPos.set(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
    
    //game mechanics
    stage = 0;
    counter = 0;
    score = 0;
    bCam = false;
    calories = 40;
    
    burgerPos.set(ofRandomWidth(),ofRandomHeight());
    burgerVel.set(ofRandom(5,6), 0);


}

//--------------------------------------------------------------
void testApp::update() {
    
// GAME MECHANICS
    counter = ofGetElapsedTimef();
    
// TRACKING UPDATE
    cam.update();
	if(cam.isFrameNew()) {
		tracker.update(toCv(cam));
		position = tracker.getPosition();
		scale = tracker.getScale();
		orientation = tracker.getOrientation();
		rotationMatrix = tracker.getRotationMatrix();
	}


    
// MMOUTH OPENESS
    prevMouth.x = mouth_width;
    prevMouth.y = mouth_height;
    mouth_width = tracker.getGesture(ofxFaceTracker::MOUTH_WIDTH) * 10;
    mouth_height = tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT) * 20;
    
    
// CHARACTER MOVE
    fat = ofMap(score, 0, 50, 0.1, 0.03);
    float catchSpeed = fat;
//    cout << fat << endl;
    trackerPos = tracker.getPosition();
    trackerPosMapped.x = ofMap(trackerPos.x, 0, 300, 0, ofGetWindowWidth());
    trackerPosMapped.y = ofMap(trackerPos.y, 0, 200,0, ofGetWindowHeight());
    //ZENO
    myPos.x = catchSpeed * trackerPosMapped.x + (1-catchSpeed) * myPos.x;
    myPos.y = catchSpeed * trackerPosMapped.y + (1-catchSpeed) * myPos.y;
    
    eyePos.set(myPos.x, myPos.y-70);
    leftEye.pos = ofPoint( eyePos.x - 35, eyePos.y );
    rightEye.pos = ofPoint( eyePos.x + 35, eyePos.y );
    

    
    ofPoint focus;

    
    // CREATING PIZZAS
    for (int i = 0; i<particleList.size(); i++) {
        particleList[i].update();
    }
    //CREATING BURGERS
    Vector<float> eyesDistBurgers;
    for (int i = 0; i<burgerList.size(); i++) {
        burgerList[i].update();
        float eyesToBurger = ofDist(burgerList[i].pos.x, burgerList[i].pos.y, eyePos.x, eyePos.y);
        eyesDistBurgers.push_back( eyesToBurger );
        
        for (int k=0; k<eyesDistBurgers.size(); k++) {
            if(eyesDistBurgers[i] > eyesDistBurgers[i+1] ){
                focus = burgerList[i].pos;
            }
        }
        
        //        float distance1 = ofDist(eyePosition.x, eyePosition.y, ballpos2.x, ballpos2.y);
        //        float distance2 = ofDist(ballpos1.x, ballpos1.y, eyePosition.x, eyePosition.y);
        //        cout << distance1 <<" || "<<  distance2 << endl;
        //
        //        if(distance1 >= distance2)  focus = ballpos2;
        //        else                        focus = ballpos1;
        //        
    }
    leftEye.mousePos = focus;
    rightEye.mousePos = focus;
    
//    burgerPos += burgerVel;
//    if(burgerPos.x > ofGetWindowWidth() || burgerPos.x < 0) burgerVel.x *= -1;
//    if(burgerPos.y > ofGetWindowHeight() || burgerPos.y < 0) burgerVel.y *= -1;
    

}

//--------------------------------------------------------------
void testApp::draw() {
	ofSetColor( 255 );
    character( myPos.x, myPos.y );
    leftEye.draw();
    rightEye.draw();
    
// TRACKING
    ofSetColor( 255 );

    if(bCam){
        ofPushMatrix();{
            ofScale(0.5, 0.5);
            cam.draw(0, 0, 640, 480);
        }ofPopMatrix();
    
        if(tracker.getFound()) {
            ofSetLineWidth(1);
            ofFill();
            tracker.draw();
        }
    }
    
// CHARACTER MOUTH
    ofPushMatrix();{
        ofSetColor(239,65,54);
        ofEllipse(myPos.x, myPos.y, (mouth_width*0.5)+10, (mouth_height*0.5)+10);
    }ofPopMatrix();
    
// DRAWING PARTICLES
    for (int i = 0; i < particleList.size(); i++) {

// EATTING MECHANICS
        float distance = ofDist(myPos.x, myPos.y, particleList[i].pos.x, particleList[i].pos.y);
        if (distance < mouthRadius && prevMouth.y + 10 < mouth_height) {
            particleList.erase(particleList.begin()+i);
            score ++;
            calories+=0.5;
        }
        
        particleList[i].draw();
    }
    
    // DRAWING BURGERS
    for (int i = 0; i < burgerList.size(); i++) {
        
        // BURGER EATTING MECHANICS
        float burgerDist = ofDist(myPos.x, myPos.y, burgerList[i].pos.x, burgerList[i].pos.y);
        if (burgerDist < mouthRadius && prevMouth.y + 10 < mouth_height) {
            burgerList.erase(burgerList.begin()+i);
            score +=5;
            calories+=1;
        }
        
        burgerList[i].draw();
    }
    
//DEBUGGING
    ofDrawBitmapStringHighlight("Score: "+ofToString(score), ofPoint(10,20));
    ofDrawBitmapStringHighlight("Time: "+ofToString(counter), ofPoint(10,40));
    
    ofRect(burgerPos, 40,40);
}
//--------------------------------------------------------------

void testApp::keyPressed(int key) {
	if (key == 'r')  tracker.reset();
    if (key == OF_KEY_UP)   score ++;
    if (key == 'c')   bCam = !bCam;
    if (key == 't')   ofToggleFullscreen() ;
    
}
//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){


}

//--------------------------------------------------------------
void testApp::character(float x,float y){
    ofPushMatrix();{
        ofTranslate(x-630, y-500);
        ofScale(1.5,1.5);
        // face circle ** FAT **
        ofFill();
        ofSetColor(245,224,205);
        ofCircle(420, 310,calories);
        // face
        ofFill();
        ofSetColor(245,224,205);
        ofBeginShape();
        ofVertex(475,312);
        ofBezierVertex(475,343,451,357,420,357);
        ofVertex(420,357);
        ofBezierVertex(389,357,364,343,364,312);
        ofVertex(364,285);
        ofBezierVertex(364,254,389,229,420,229);
        ofVertex(420,229);
        ofBezierVertex(451,229,475,254,475,285);
        ofVertex(475,312);
        ofEndShape();
        // left eye outter
//        ofFill();
//        ofSetColor(255);
//        ofBeginShape();
//        ofVertex(461,286);
//        ofBezierVertex(461,296,453,304,443,304);
//        ofBezierVertex(433,304,425,296,425,286);
//        ofBezierVertex(425,276,433,268,443,268);
//        ofBezierVertex(453,268,461,276,461,286);
//        ofEndShape();
//        // left eye - pupil
//        ofFill();
//        ofSetColor(35,31,32);
//        ofBeginShape();
//        ofVertex(449,286);
//        ofBezierVertex(449,290,446,292,443,292);
//        ofBezierVertex(440,292,437,290,437,286);
//        ofBezierVertex(437,283,440,281,443,281);
//        ofBezierVertex(446,281,449,283,449,286);
//        ofEndShape();
//        // right eye outter
//        ofFill();
//        ofSetColor(255,255,255);
//        ofBeginShape();
//        ofVertex(415,286);
//        ofBezierVertex(415,296,407,304,397,304);
//        ofBezierVertex(387,304,379,296,379,286);
//        ofBezierVertex(379,276,387,268,397,268);
//        ofBezierVertex(407,268,415,276,415,286);
//        ofEndShape();
//        // right eye pupil
//        ofFill();
//        ofSetColor(35,31,32);
//        ofBeginShape();
//        ofVertex(403,286);
//        ofBezierVertex(403,290,400,292,397,292);
//        ofBezierVertex(394,292,391,290,391,286);
//        ofBezierVertex(391,283,394,281,397,281);
//        ofBezierVertex(400,281,403,283,403,286);
//        ofEndShape();
        // NOSE
        ofNoFill();
        ofSetLineWidth(1);
        ofSetColor(176,136,116);
        ofBeginShape();
        ofVertex(407,311);
        ofBezierVertex(407,311,404,317,419,318);
        ofBezierVertex(432,318,431,311,431,311);
        ofEndShape();
        //MOUTH
        ofFill();
        ofSetColor(239,65,54);
        ofEllipse(420, 335, 20, 10);
//        ofBeginShape();
//        ofVertex(384,338);
//        ofBezierVertex(384,343,399,347,419,347);
//        ofBezierVertex(438,347,453,343,453,338);
//        ofBezierVertex(453,332,438,328,419,328);
//        ofBezierVertex(399,328,384,332,384,338);
//        ofEndShape();
        ofFill();
        ofSetColor(35,31,32);
        ofBeginShape();
        ofVertex(380,261);
        ofBezierVertex(380,263,381,265,383,265);
        ofVertex(408,265);
        ofBezierVertex(410,265,412,263,412,261);
        ofVertex(412,261);
        ofBezierVertex(412,259,410,257,408,257);
        ofVertex(383,257);
        ofBezierVertex(381,257,380,259,380,261);
        ofVertex(380,261);
        ofEndShape();
        ofFill();
        ofSetColor(35,31,32);
        ofBeginShape();
        ofVertex(427,261);
        ofBezierVertex(427,263,428,265,431,265);
        ofVertex(455,265);
        ofBezierVertex(458,265,459,263,459,261);
        ofVertex(459,261);
        ofBezierVertex(459,259,458,257,455,257);
        ofVertex(431,257);
        ofBezierVertex(428,257,427,259,427,261);
        ofVertex(427,261);
        ofEndShape();

    }ofPopMatrix();
    
}

