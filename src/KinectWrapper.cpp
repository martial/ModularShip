/*
 *  KinectWrapper.cpp
 *  ModularShip
 *
 *  Created by Martial Geoffre on 15/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "KinectWrapper.h"

void KinectWrapper::setup () {
	
	
	kinect.init();
	//kinect.init(true);  // shows infrared instead of RGB video image
	//kinect.init(false, false);  // disable infrared/rgb video iamge (faster fps)
	kinect.setVerbose(true);
	//kinect.open();
	
	bStarted = false;
	
	angle = 0;
	depth = 2.0;
	step = 8;
}

void KinectWrapper::update() {
	kinect.update();
	
	int w = 640;
	int h = 480;
	
	float* distancePixels = kinect.getDistancePixels();
	
	
	points.clear();
	
	for(int y = 0; y < h; y += step) {
		for(int x = 0; x < w; x += step) {
						
			ofPoint cur = kinect.getWorldCoordinateFor(x, y);
			
			if ( cur.z < depth ) {
				points.push_back(cur);
			}
			
		}
	}
	
	
	
}

void KinectWrapper::increaseAngle(bool bIsIncreasing) {
		
	if ( bIsIncreasing ) {
		angle++;
		if(angle>30) angle=30;
			
	} else {
		angle--;
		if(angle<-30) angle=-30;	
	}
	kinect.setCameraTiltAngle(angle);
}

void KinectWrapper::connect () {
	kinect.setCameraTiltAngle(angle);	// go back to prev tilt
	kinect.open();
	bStarted = true;

}

void KinectWrapper::disconnect () {
	exit();
}

void KinectWrapper::exit() {
	kinect.setCameraTiltAngle(0); // zero the tilt on exit
	kinect.close();
	bStarted = false;
}


void KinectWrapper::debugDraw () {
	
	float scale = 10.0;
	
	glBegin(GL_POINTS);
	glColor3ub(255,0,0);
	ofSetColor(255, 0, 0);
	for(int y = 0; y < points.size(); y +=2) {
		
		ofPoint pnt = points[y];
		pnt.x = ( 1 + pnt.x ) * scale;
		pnt.z *= scale;
		
		glVertex2f(pnt.x*10, pnt.z*10);
		
		//printf("pnt.x  %f\n", pnt.x);
		
	}
	glEnd();
	
	
	
}
