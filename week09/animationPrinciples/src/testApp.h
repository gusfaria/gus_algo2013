#pragma once

#include "ofMain.h"
#include "Element.h"

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
		

    vector <Element> Elements;

    ofColor color, color2;
    int counter;
    int startTime, time;
    bool bBg;
};



//change setColor and background color (create bool)
// fix the extra rect being created