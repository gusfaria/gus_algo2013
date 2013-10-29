

//With assistance of Anthony Marafat's code:
//https://github.com/SafetyOrange/Algorithmic-Animation-2013/tree/master/Week%209/squatch




#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofVec2f pos;
    float w,h;
    float vel;
    float acc;
    
    float threshold;
		
};




