/*
 *  guiCreator.h
 *  ModularShip
 *
 *  Created by Martial Geoffre on 11/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GUICRTOR
#define GUICRTOR

#include "ofMain.h"
#include "ofxTubeManager.h"
#include "ofxSoundManager.h"
#include "guiPanel.h"

class guiCreator {
		
public:
	
	void setup(ofxTubeManager * tubesManager, ofxSoundManager * sndManager, guiPanel * panel);
	void update();
	
	ofxTubeManager * tubesManager;
	ofxSoundManager * sndManager;
	guiPanel * panel;
	
	ofxSimpleGuiSliderInt * verticalSlider;
	
	
	
	
};

#endif