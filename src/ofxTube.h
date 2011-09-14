/*
 *  ofxTube.h
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 26/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef OFXTUBE
#define OFXTUBE

#include "ofMain.h"
#include "ofxTubeEvent.h"
#include "ofxTween.h"
#include "ofxEasingQuint.h"
#include "ofxEasingLinear.h"
#include "ofxEasingSine.h"
#include "ofxTubePixel.h"
#include "ofxTimer.h"

class ofxTube {
	
public:

	ofxTube();
	
	
	void setup(int size, int numOfPixels);
	void update();
	void drawFor2DView(float x, float y);
	void drawFor3DView(float x, float y, ofVec4f rotation);
	void drawForDisplay(float x, float y);
	void drawForPreview (float x, float y);
	void setActive(bool bActive);
	
	
	/* */
	
	void reset();
	void setMainAlphaPct (float pct);
	void changeSizePct(float sizePct, float time );
	void setAllPixelAlpha( float alpha , float duration);
	void setPixelAlpha(int pixelIndex, float alpha, float duration, float delay = 0.0);
	
	ofVec3f					getPositionFor3D();
	
	int						id;
	int						mappingId;
	
	bool					bVertical;
	
	float					alphaPct;
	float					sizePct;
	float					globalSizePct;
	float					dumbPct;
	bool					bActive;
	bool					bFlickering;
	int						flickeringRange;
	
	float					nextTimeActive;
	float					nextTimeInactive;
	
	ofVec3f					pos3D;
	
	ofColor					color1;
	ofColor					color2;
	vector<ofxTubePixel*>	pixels;

	
	ofEvent<ofxTubeEvent>	activeEvent;
	ofEvent<ofxTubeEvent>	updateEvent;
	
	ofxTween				sizePctTween;
	ofxTween				dumbPctTween;
	ofxEasingQuint			easingquint;
	ofxEasingLinear			easingLinear;
	ofxEasingSine			easingSine;
	
	bool					bDumbPctIncrease;
	float					oldDumbPct;
	ofxTimer				timer;
	
	float					stageAlphaPct;
	
private:
		
	int						size;
	int						numOfPixels;
	float					mainAlphaPct;
	
	
	
	
};

#endif