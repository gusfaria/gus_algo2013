#pragma once

#include "ofMain.h"
#define STRINGIFY(A) #A


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
    
        void wave(float angleBase,int amp, int rectW, int rectH);
        vector <ofPoint> pointList;
    
    float angleAdder;
    float angle;
    
    ofVideoGrabber cam;
    ofShader hBlur, vBlur;
    ofFbo buffer[2];
};
