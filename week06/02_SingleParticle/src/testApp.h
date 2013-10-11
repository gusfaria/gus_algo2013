#pragma once

#include "ofMain.h"

#include "Particle.h"

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
    
        void addParticle(ofPoint _pos);
		
        ofPoint pos;
        vector <Particle> particleList;
        ofImage myCard;
    
//    TO DO:
//    Click and create a individual card
//    when keypress cards go in different velocities and bounce against the "floor"



};


