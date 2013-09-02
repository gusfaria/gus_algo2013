#ifndef __sharperControls__Element__
#define __sharperControls__Element__

#include <iostream>
#include "ofMain.h"

#endif /* defined(__sharperControls__Element__) */


class element {
    
public:
	
    element();
	
    void	draw();
    void	update(float zeno);
    float		size;
    float		zenoSpeed;		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
	
    
};
