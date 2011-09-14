/*
 *  ofxTubePixel.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 05/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxTubePixel.h"
#include "mainSettings.h"

ofxTubePixel::ofxTubePixel () {
	
	numOfPixels = mainSettings::getNumOfTubePixels();
	
	alphaPct = 1.0;
	pos.x = 0;
	pos.y = 0;
	
	tweenPosY.setParameters(0, quint, ofxTween::easeOut, 0, pos.y, 1, 0);
	tweenAlpha.setParameters(0, quint, ofxTween::easeOut, 0,1.0, 1, 0);
}

void ofxTubePixel::init () {
	//this->parentPct = parentPct;
}

void ofxTubePixel::update() {
	pos.y =		tweenPosY.update();
	alphaPct =  tweenAlpha.update();
}

void ofxTubePixel::reset () {
	
}

void ofxTubePixel::setPosition(float x, float y, float duration) {
	tweenPosY.setParameters(0, quint, ofxTween::easeOut, pos.y, y, duration, 0);
}

void ofxTubePixel::setPositionIn(float x, float y, float duration) {
	tweenPosY.setParameters(0, quint, ofxTween::easeIn, pos.y, y, duration, 0);
}

void ofxTubePixel::setPositionInOut(float x, float y, float duration) {
	tweenPosY.setParameters(0, quint, ofxTween::easeIn, pos.y, y, duration, 0);
}

void ofxTubePixel::setAlphaPct(float pct, float duration, float delay) {
	
	tweenAlpha.setParameters(0, quint, ofxTween::easeOut, alphaPct, pct, duration, delay);
	
}


void ofxTubePixel::drawForPreview(float x, float y , float alpha) {
	
	ofSetColor((int)color.r, (int)color.g,(int)color.b, alphaPct * alpha * 255);
	
	glPushMatrix();
	ofRect(x+(pos.y*5), y, 5, 5);
	glPopMatrix();
}



void ofxTubePixel::drawFor3DView(float x, float y, float z, float alpha) {
	
	
	
	ofSetColor((int)color.r, (int)color.g,(int)color.b, alphaPct * alpha * 255);
	
	
	float pixelSize = 10.0 / 36.0;
   
	glPushMatrix();
	glVertex2d(x+pos.x,y+pos.y);
	glPopMatrix();
}

void ofxTubePixel::drawForDisplay(float x, float y, float alpha) {
	
    if ( alphaPct <= 0.0 ) return;
	
	
	
	//ofPushMatrix();
	
//	glTranslated((int)x, (int)y, 0);
	ofSetColor((int)color.r, (int)color.g,(int)color.b, alphaPct * alpha * 255);
	//ofSetColor(255,0,0);
	//glColor4d(1,0,0,1);
	//printf("pos.y %d\n", (int)pos.y);
	ofRect(0, pos.y, 1, 1);
	
	
	 

	
	//glVertex2d((int)(x+pos.y), (int)y);
	//glEnd();
	//glVertex2d(0, pos.y);
	//ofPopMatrix();
	

}