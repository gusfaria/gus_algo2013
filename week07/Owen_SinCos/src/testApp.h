#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "Particle.h"

class testApp : public ofBaseApp{
	public:
		void setup();
        void exit();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void onGuiEvent( ofxUIEventArgs &e );
    ofxUICanvas *gui;
    
    void createParticle();
    
    vector <Particle> pList;
    
    float sinChange;
    float cosChange;
    float velX;
    float pDiameter;
    float reset;
    
    int 				snapCounter;
    char 				snapString[255];
    ofImage 			img;
    bool 				bSnapshot;
};

// add a camera
// add a switch for the controls
