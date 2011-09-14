/*
 *  ofxColorTubeManager.h
 *  LightField
 *
 *  Created by Martial Geoffre on 04/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CLRTBMNGR
#define CLRTBMNGR

#include "ofMain.h"
#include "ofxColorUtils.h"
#include "ofxTube.h"
#include "guiPanel.h"
#include "ofxSoundManager.h"

class superInterfacePanel;

class ofxColorTubeManager {
			
public:
	
	void setup(vector<ofxTube*> * tubes, superInterfacePanel * panel);
	void update();
	void setColors();
	
	void setMode(int index);
	void doNormalGradient();
	void doHorizontalGradient();
	void doVerticalGradient();
	void doSymetricHorizontalGradient();
	void doTestColor();
	
	void doSymetricVerticalGradient();
	
	
	
	int	mode;		

private:
	
	vector<ofxTube*>	*	tubes;
	superInterfacePanel			*	panel;
	
	int						total;
	ofxColorUtils			colorUtils;
	ofxColorUtils			colorUtilsTube;
	ofPoint					coords;
	int						numOfTubePixels;
	
};

#endif