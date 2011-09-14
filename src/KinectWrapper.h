/*
 *  KinectWrapper.h
 *  ModularShip
 *
 *  Created by Martial Geoffre on 15/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef KNCTWRAPPER
#define KNCTWRAPPER

#include "ofMain.h"
#include "ofxKinect.h"


class KinectWrapper  {
	public :
	
	void setup();
	void update();
	void debugDraw();
	
	void connect();
	void disconnect();
	void exit();
	
	void increaseAngle(bool bIsIncreasing);
	
	bool bStarted;
	
	float				depth;
	int					angle, step;
	ofxKinect 			kinect;
	vector<ofPoint>		points;
	
};

#endif