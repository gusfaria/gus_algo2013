#pragma once

#include "ofMain.h"
#include "VectorField.h"
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

    
        VectorField myVectorField;
        vector <Particle> particleList;
    
//        bool bPerlin;
        bool bMouse;
        bool bHide;
    
        ofColor color;
    
    ofImage img, img2;
};


// make it change img by time ( união faz a força )
// drag an drop img...
