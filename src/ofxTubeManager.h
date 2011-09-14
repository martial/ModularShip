/*
 *  ofxTubeManager.h
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 26/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef OFXTUBEMNGR
#define OFXTUBEMNGR

#include "ofMain.h"
#include "ofxTube.h"
#include "ofxSoundManager.h"
#include "mainAnimData.h"
#include "frameData.h"

#include "ofxAnimPlayer.h"
#include "TubeAnimationManager.h"
#include "superInterfacePanel.h"
#include "ofxColorTubeManager.h"
#include "ofxSoundTubeManager.h"
#include "ofxColorUtils.h"
//#include "KinectWrapper.h"
#include "Stroboscope.h"
#include "RandomStroboscope.h"
#include "Equalizer.h"


class superInterfacePanel;

class ofxTubeManager {
	
public:
	
	ofxTubeManager();
	void setup(ofxSoundManager * sndManager, mainAnimData * animData, superInterfacePanel * panel);
	void update();
	
	//void	 updateVbo();
	//void	 drawVbo();
	ofFbo *  drawForDisplay(int x, int y);
	
	void setAnimation (int id);
	void pushAnimation();
	void popAnimation();
	
	void setStageOpacity(float pct);
	
	void increaseAnimation(bool bIncreasing);
	
	void setActivePoints (frameData * frame);
	void setActivePoints (vector<int> * activePoints);
	
	void enableFlickering(bool bFlickering);
	void setFlickeringRange(int val);
	
	void forceSimpleVertical (bool bEnabled);
	
	void resetTubesState();
	
	void roundRotations (int & rot);
	
	ofxAnimPlayer					player;
	TubeAnimationManager			vAnimationManager;
	ofxColorTubeManager				colorManager;
	ofxSoundTubeManager				soundManager;
	Stroboscope						strob;
	RandomStroboscope				rdmStrob;
	Equalizer						equalizer;
	
	vector<ofxTube*>				tubes;
	vector<ofxTube*>				tubesLeft;
	vector<ofxTube*>				tubesRight;
	
	int								panelOneRotX, panelTwoRotX, panelOneRotY, panelTwoRotY;
	
	mainAnimData			*		animData;
	int								currentAnimation;
	int								oldVerticalAnim;
	
	bool							bKinectMode;
	bool							bFlickering;
	bool							bSequencerMode;
	vector<int>						sequencerActivePnts;
	
	private	:
	
	ofxSoundManager			*		sndManager;
	superInterfacePanel				*		panel;
	frameData				*		currentFrame;
	//KinectWrapper			*		kinect;
	
	
		
	ofxColorUtils					colorUtils;
	
	int								total;
	
	int								lastFrame;
	
	
	ofFbo							displayFbo;
	
	/* Interaction modes */ 
	
	bool							sizeSoundEnabled, reverseFilled;
	
	/* */
	
	/* VBOS 	
	ofVbo							pixel3DVbo;
	ofVec3f							pixel3DVboPos[19712];
	ofColor							pixel3DVboColor[19712];
	 */

	 
};

#endif