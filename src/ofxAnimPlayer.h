/*
 *  ofxAnimPlayer.h
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 28/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef OFXANIPLAYER
#define OFXANIPLAYER

#include "ofMain.h"
#include "animationData.h"
#include "frameData.h"

class ofxAnimPlayer {

	public : 
	
	ofxAnimPlayer();
	void setup();
	frameData * update();
	frameData * getCurrentFrameData ();
	
	
	void resetFrame();
	void pushAnimation();
	void popAnimation();
	
	void pushFrame();
	
	void setSpeedPct(float speedPct);
	
	void toggleSens(bool val);
	
	void setAnimation (animationData * animation);
	void setSpeed(float speed);
	
	ofEvent<int>				animationLoopEvent;
	
	float						speed;
	
	animationData		*		currentAnimationData;
	float						timeElapsedSpeed;
	
	
	int							id;
	
	int							currentFrame;
	
	bool						bSpeedByframe;
	bool						reverseMode;
	float						framePct;
	
	int							sens;
	float						minSpeed;
	
	bool						tapTempoEnabled;
	
	private:
	
	
	
	
	int							timeStep;
	;
	
	
	
	
	float						realSpeed;
	float						speedAlpha;
	
};

#endif
