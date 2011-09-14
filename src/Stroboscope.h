/*
 *  Stroboscope.h
 *  ModularShip
 *
 *  Created by Martial Geoffre on 19/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef STRBOSCOP
#define STRBOSCOP

#include "ofMain.h"
#include "ofxTube.h"

class Stroboscope {
		
public:
	
	void init (vector<ofxTube*> * tubes);
	void update();
	
	bool bEnabled;
	int intensity;
	
	vector<ofxTube*> * tubes;
};


#endif