/*
 *  RandomStroboscope.h
 *  ModularShip
 *
 *  Created by Martial Geoffre on 24/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef RDMSTRBOSCOP
#define RDMSTRBOSCOP

#include "ofMain.h"
#include "ofxTube.h"

class RandomStroboscope {
	
public:
	
	void init (vector<ofxTube*> * tubes);
	void update();
	
	bool bEnabled;
	int intensity;
	
	vector<ofxTube*> * tubes;
};


#endif