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
    
    font16.loadFont("pastelaria.ttf", 16);
    font30.loadFont("pastelaria.ttf", 30);
    
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
    gamestate = 0;
    counter = 0;
    score = 0;
    bCam = false;
    calories = 40;
    username = "Enter your name here";
    startedNameEntry = false;
    bFirst  = false;
    
    loadXMLData();
    cout << numberOfSavedScores << endl;
}

//--------------------------------------------------------------
void testApp::update() {
    
    
    // TRACKING UPDATE
    trackerupdate();
    
    // MMOUTH OPENESS
    prevMouth.x = mouth_width;
    prevMouth.y = mouth_height;
    mouth_width = tracker.getGesture(ofxFaceTracker::MOUTH_WIDTH) * 10;
    mouth_height = tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT) * 20;
    
    
    // CHARACTER MOVE
    fat = ofMap(score, 0, 50, 0.1, 0.03);
    float catchSpeed = fat;
    ofVec2f trackerPosMapped, trackerPos;
    trackerPos = tracker.getPosition();
    
    trackerPosMapped.x = ofMap(trackerPos.x, 0, 300, 0, ofGetWindowWidth());
    trackerPosMapped.y = ofMap(trackerPos.y, 0, 200,0, ofGetWindowHeight());
    
    
    trackerPosMapped.x = ofGetWindowWidth() - trackerPosMapped.x;
    //ZENO
    myPos.x = catchSpeed * trackerPosMapped.x + (1-catchSpeed) * myPos.x;
    myPos.y = catchSpeed * trackerPosMapped.y + (1-catchSpeed) * myPos.y;
    
    //creating the eyes
    eyePos.set(myPos.x, myPos.y-70);
    leftEye.pos = ofPoint( eyePos.x - 35, eyePos.y );
    rightEye.pos = ofPoint( eyePos.x + 35, eyePos.y );
    
    if(gamestate == 1){
        // CREATING PIZZAS
        for (int i = 0; i<particleList.size(); i++) {
            particleList[i].update();
        }
        // CREATING BURGERS
        for (int i = 0; i<burgerList.size(); i++) {
            burgerList[i].update();
        }
        
        //EYES FOCUS
        float eyesToBurger = ofDist(burgerList[0].pos.x, burgerList[0].pos.y, eyePos.x, eyePos.y);
        ofPoint focus = burgerList[0].pos;
        leftEye.mousePos = focus;
        rightEye.mousePos = focus;
    }
    // GAME MECHANICS
    if(gamestate == 0){
        if(!startedNameEntry){
            username = "Enter your name here";
        }
    }
    
    if(gamestate == 1){
        counter = (80 - ofGetElapsedTimef());
        if(counter == 0 || gamestate == 2) {
            gamestate = 2;
            highScores.addTag("game");
            highScores.pushTag("game", numberOfSavedScores);{
                highScores.addValue("username", username);
                highScores.addValue("score", score);
            }highScores.popTag();
            
            highScores.saveFile("highScores.xml");
        }
    }
    
    if(gamestate == 2){
        loadXMLData();
        sortScores();
    }
    
}

//--------------------------------------------------------------
void testApp::draw() {
    
    ofSetColor( 255 );
    character( myPos.x, myPos.y );
    leftEye.draw();
    rightEye.draw();
    
    // TRACKING
    trackerdraw();
    
    // CHARACTER MOUTH
    ofPushMatrix();{
        ofSetColor(239,65,54);
        ofEllipse(myPos.x, myPos.y, (mouth_width*0.5)+10, (mouth_height*0.5)+10);
    }ofPopMatrix();
    
    if (gamestate == 0) {
        ofPushStyle();{
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofSetColor(255, 20);
            ofRect(ofGetWindowWidth()/2, 100, 250, 40);
        }ofPopStyle();
        
        font16.drawStringCentered(username, ofGetWindowWidth()/2, 100);
        ofSetColor(ofRandom(255),0,0,80);
        font30.drawStringCentered("PRESS 'RETURN' WHEN YOU ARE READY", ofGetWindowWidth()/2, ofGetWindowHeight()/2);
        
    } else if(gamestate == 1){
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
        ofSetColor(0);
        font16.drawString("Score: "+ofToString(score), 30, 30);
        font16.drawString("Time: "+ofToString(counter), ofGetWindowWidth()-100, 30);
        
    } else if(counter <= 0 || gamestate == 2 || particleList.size() == 0){
        particleList.clear();
        ofSetColor(ofRandom(255),0,0,80);
        font30.drawStringCentered("CONGRATULATIONS "+ username + "!\nYOUR SCORE IS "+ofToString(score), ofGetWindowWidth()/2, 100);
    }
    
    if(gamestate == 2){
        ofPushStyle();{
            ofSetColor(0);
            if (savedScores.size() < 8) {
                for (int i = 0; i < savedScores.size(); i++) {
                    font16.drawString(ofToString(i+1) + ". ", 300+120, 330 + i * 28);
                    font16.drawString(sortedNames[i], 330+120, 330 + i * 28);
                    font16.drawString(ofToString(sortedScores[i]), 850+120, 330 + i * 28);
                }
            } else if (savedScores.size() >= 5) {
                for (int i = 0; i < 5; i++) {
                    font16.drawString(ofToString(i+1) + ". ", 300 + 120, 330 + i * 28);
                    font16.drawString(sortedNames[i], 330 + 120, 330 + i * 28);
                    font16.drawString(ofToString(sortedScores[i]), 850 + 120, 330 + i * 28);
                }
            }
        }ofPopStyle();
        ofDrawBitmapStringHighlight("SPECIAL THANKS TO: CHARLIE WHITNEY, JENNIFER PRESTO, MATT FELSEN, ALBERT 'DA MENG' KIM, BERNARDO SCHORR AND McDONALDS!", ofPoint(10,ofGetWindowHeight()-30));
    }
    
}
//--------------------------------------------------------------
void testApp::loadXMLData() {
    // start fresh
    numberOfSavedScores = 0;
    savedNames.clear();
    savedScores.clear();
    
    if( highScores.loadFile("highScores.xml") ){
        numberOfSavedScores = highScores.getNumTags("game");
		cout << "highScores.xml loaded! there are " << numberOfSavedScores << " scores loaded!" << endl;
        for (int i = 0; i < numberOfSavedScores; i++) {
            highScores.pushTag("game", i);{
                string tmpName = highScores.getValue("username", " ");
                int tmpScore = highScores.getValue("score", 0);
                savedNames.push_back(tmpName);
                savedScores.push_back(highScores.getValue("score", 0));
            }highScores.popTag();
        }
	}else{
		cout << "unable to load highScores.xml check data/ folder" << endl;
        numberOfSavedScores = 0;
	}
}

//--------------------------------------------------------------
void testApp::sortScores() {
    
    // start fresh
    sortedScores.clear();
    sortedNames.clear();
    
    for (int i = 0; i < savedScores.size(); i++) {
        // cout <<  "name: " << savedNames[i] << " score: " << savedScores[i] << endl;
    }
    for (int i = 0; i < savedScores.size(); i++) {
        float compareNum = -20.0; // arbitrary low number
        int indexNum = -1;
        for (int j = 0; j < savedScores.size(); j++) {
            if (savedScores[j] > compareNum) {
                // cout << "Good [#" << j << "]: " << savedScores[j] << " is bigger than " << compareNum << endl;
                compareNum = savedScores[j];
                indexNum = j;
            }
        }
        sortedScores.push_back(compareNum);
        // cout << "push back to sortedScores" << endl;
        sortedNames.push_back(savedNames[indexNum]);
        // cout << "push Back to sortedNames" << endl;
        savedScores[indexNum] = -500; // arbitrary really low number
        // cout << "saving that one at -500" << endl;
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
	
    if (key == OF_KEY_RETURN ){
        gamestate ++;
        savedNames.push_back(username);
        ofResetElapsedTimeCounter();
        startedNameEntry = false;
    }
    
    if(startedNameEntry){
        if(key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
            username = username.substr(0, username.length()-1);
            
        } else if (key > 31 && key < 127){
            
            if( bFirst ){
                username.clear();
                bFirst = false;
            }
            
            username.append(1, (char)key);
        }
    } else {
        if (key == 'R') setup();
        if (key == 'r')  tracker.reset();
        if (key == OF_KEY_UP)   score ++;
        if (key == 'C')   bCam = !bCam;
        if (key == 'T')   ofToggleFullscreen() ;
    }
}
//--------------------------------------------------------------
void testApp::trackerupdate(){
    cam.update();
	if(cam.isFrameNew()) {
        
		tracker.update(toCv(cam));
		position = tracker.getPosition();
		scale = tracker.getScale();
		orientation = tracker.getOrientation();
		rotationMatrix = tracker.getRotationMatrix();
	}
}
//--------------------------------------------------------------
void testApp::trackerdraw(){
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
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    ofPushStyle();{
        ofRectangle _switch = ofRectangle(ofGetWindowWidth()/2-80, 80, 300, 100);
        if (_switch.inside(x, y)) {
            startedNameEntry = true;
            username.clear();
            cout << "input clicked" << endl;
        } else {
            startedNameEntry = false;
        }
    }ofPopMatrix();
    
    
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
        // FACE
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
        //i dont care anymore
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

