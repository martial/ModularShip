/*
 *  Equalizer.h
 *  ModularShip
 *
 *  Created by superscript_tower on 26/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef BIGEQUIALIZER
#define BIGEQUIALIZER

#include "ofMain.h"
#include "ofxTube.h"
#include "ofxSoundManager.h"

class Equalizer {
	
public:
	
	void init (vector<ofxTube*> * tubes, ofxSoundManager * sound);
	void update();
	
	void doVerticalEqualizer();
	void doHorizontalEqualizer();
	
	bool bEnabled;
	int intensity;
	
	int mode;
	
	vector<ofxTube*> * tubes;
	ofxSoundManager * sound;
	
	ofPoint			coords;
};


#endif