/*
 *  ofxSoundTubeManager.h
 *  LightField
 *
 *  Created by Martial Geoffre on 06/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef OFXSNDTBMNGR
#define OFXSNDTBMNGR

#include "ofMain.h"
#include "ofxSoundManager.h"
#include "ofxAnimPlayer.h"
#include "ofxTube.h"

class ofxSoundTubeManager {
	
public :

	ofxSoundTubeManager();
	
	void setup(ofxSoundManager * soundManager, vector<ofxTube*> * tubes, ofxAnimPlayer * animPlayer);
	void update();
	
	void changeMode (int mode);
	
	void doNormalGrid();
	
	void doVerticalStereo();
	void doHorizontalStereo();
	
	void doVerticalCenteredStereo();
	void doHorizontalCenteredStereo();
	
	int						mode;
	bool					opacitySoundEnabled;
	bool					sizeSoundEnabled;
	bool					speedEnabled;
	
private :
	
	ofPoint					coords;
	
	ofxSoundManager		*	soundManager;
	ofxAnimPlayer		*	animPlayer;
	vector<ofxTube*>	*	tubes;
	
	int						total;
	
	
};

#endif

