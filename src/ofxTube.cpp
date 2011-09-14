/*
 *  ofxTube.cpp
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 26/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxTube.h"
#include "mainSettings.h"

ofxTube::ofxTube() {
	
	nextTimeActive = 0.0;
	mainAlphaPct = 1.0;
	alphaPct = 1.0;
	sizePct = 1.0;
	globalSizePct = 1.0;
	stageAlphaPct = 1.0;
	bActive = true;
	bFlickering = false;
	
	bVertical = true;
	
	numOfPixels = mainSettings::getNumOfTubePixels();
	
	pos3D.set(0, 0, 0);
	
	pixels.reserve(numOfPixels);
	
	for ( int i=0; i<numOfPixels; i++ ) {
		ofxTubePixel * pixel = new ofxTubePixel();
		pixel->init();
		ofColor white;
		white.set(255,255,255);
		
		pixel->setPosition(0, i);
		pixel->color = white;
		pixel->alphaPct = 1.0;
		
		//pixelsAlphaPct[i] = 1.0;
		pixels[i] = pixel;
		
		
	}
	
	sizePctTween.setParameters(0, easingquint, ofxTween::easeOut, 0, 1, 1000, 0);
	sizePctTween.start();
	
	dumbPctTween.setParameters(0, easingquint, ofxTween::easeOut, 0, 0, 1, 0);
	dumbPctTween.start();
	
	
}

void ofxTube::setup(int size, int numOfPixels) {
	
	this->size = size;
	//this->numOfPixels = numOfPixels;
	
}
void ofxTube::update() {
	
	sizePct = sizePctTween.update();
	dumbPct = dumbPctTween.update();
	
	bDumbPctIncrease = ( dumbPct > oldDumbPct );
	oldDumbPct = dumbPct;
	
	for ( int i = 0; i<numOfPixels; i++ ) {
		pixels[i]->update();
	}
	
	
	static ofxTubeEvent args;
	args.id = this->id;
	args.bActive = bActive;
	
	ofNotifyEvent(updateEvent, args, this); 
	
	//sizePct = 1.0;
}

void ofxTube::setActive(bool bActive) {
	
	
	
	
	if  ( bActive == this->bActive ) return;
	
	this->bActive = bActive;
	static ofxTubeEvent args;
	args.id = this->id;
	args.bActive = bActive;
	
	ofNotifyEvent(activeEvent, args, this); 
}



/*
 
 Useful actions
 
 
 */

void ofxTube::reset() {
	
	//bFlickering = false;
	mainAlphaPct = 1.0;
	
	globalSizePct = 1.0;
	if ( sizePct != 1.0 ) changeSizePct(1.0, 0.0);
	for ( int i = 0; i<numOfPixels; i++ ) {
		if (pixels[i]->alphaPct != 0 ) pixels[i]->setAlphaPct(0.0, 0.0);
		if (pixels[i]->pos.y != i ) pixels[i]->setPosition(0, i, 0.0);
	}
	dumbPctTween.setParameters(0, easingquint, ofxTween::easeOut, dumbPct, 0.0, 0.0, 0);

}

void ofxTube::changeSizePct(float sizePct, float time ) {
	
	sizePctTween.setParameters(0, easingSine, ofxTween::easeOut, this->sizePct, sizePct, time, 0);
	sizePctTween.start();
}

void ofxTube::setPixelAlpha(int pixelIndex, float alpha, float duration, float delay) {
	
	//ofColor * pixelAlpha = pixelsAlphaPct[pixelIndex];
	if ( pixelIndex > numOfPixels-1 ) return;
	pixels[pixelIndex]->setAlphaPct(alpha, duration, delay);
	
}

void ofxTube::setAllPixelAlpha( float alpha , float duration) {
	
	//ofColor * pixelAlpha = pixelsAlphaPct[pixelIndex];
	for ( int i=0; i<numOfPixels; i++) {
	pixels[i]->setAlphaPct(alpha, duration);
	}
	
}

void ofxTube::setMainAlphaPct (float pct) {
	mainAlphaPct = pct;
}



void ofxTube::drawFor2DView(float x, float y) {
		
	ofEnableAlphaBlending();
	
	ofSetColor(255, 255, 255, 255);	
		
	glPushMatrix();
	glTranslatef(x+5, y, 0);
	
	if ( bActive ) {
		ofSetColor(255, 255, 255);
	} else {
		ofSetColor(255, 255, 255, 125);
	}
	
	glScalef(1, 1, 1);
	ofRect(-20, -40, 20, 40);
	glPopMatrix();
	
	ofDisableAlphaBlending();
	

	
	
}


void ofxTube::drawForPreview (float x, float y) {
	
	if ( bFlickering && ofGetFrameNum() % flickeringRange != 0 ) return;
	
	
	ofEnableAlphaBlending();
	ofPushMatrix();
	
	ofSetColor(255, 255, 255, 255 * mainAlphaPct);	
	
	glTranslated((int)x, (int)y, 0);
	
	//glRotatef(90.0, 0.0, 0.0, 1.0);
	
	
	glTranslatef((float)numOfPixels/2.0, 0, 0);
	glScalef(sizePct, 1, 1);
	glTranslatef(-(float)numOfPixels/2.0, 0, 0);	
	
	
	//glBegin(GL_POINTS);
	for ( int i = 0; i<numOfPixels; i++ ) {
		pixels[i]->drawForPreview(0,0,mainAlphaPct);
	}
	//glEnd();
	//glTranslatef(-numOfPixels*.5, y, 0);
	
	ofPopMatrix();
	ofDisableAlphaBlending();
	
	
}

void ofxTube::drawFor3DView(float x, float y, ofVec4f rotation) {
	
	if ( bFlickering && ofGetFrameNum() % flickeringRange != 0 ) return;
	
	
	if ( sizePct == 0.0 ) return;
	//if(bActive ) return;
		
	ofEnableAlphaBlending();
	ofPushMatrix();
	
	ofSetColor(255, 255, 255, 255);	
	
	pos3D.set(x, y, 0);
	
	
	glTranslatef(x, y, 0);
	//glTranslatef(numOfPixels/2, 0, 0);
	glRotatef(rotation.x, rotation.y, rotation.z, rotation.w);
	//glTranslatef(-numOfPixels, 0, 0);
	
	if ( sizePct < .1 ) sizePct = 0;
	glTranslatef(0, numOfPixels/2, 0);
	glScalef(1, sizePct, 1);
	glTranslatef(0, -numOfPixels/2, 0);
	
	
	glBegin(GL_POINTS);
	for ( int i = 0; i<numOfPixels; i++ ) {
		ofxTubePixel * pixel = pixels[i];
		pixel->drawFor3DView(0, 0, 0,mainAlphaPct* stageAlphaPct);
		
	}
	glEnd();
	
	ofPopMatrix();
	ofDisableAlphaBlending();
		
	
}

void ofxTube::drawForDisplay(float x, float y) {
	
	if ( bFlickering && ofGetFrameNum() % flickeringRange != 0 ) return;
	
	
	ofEnableAlphaBlending();
	ofPushMatrix();
	
	ofSetColor(255, 255, 255, 255 * mainAlphaPct * stageAlphaPct);	
	
	glTranslated((int)x, (int)y, 0);
	
	glRotatef(90.0, 0.0, 0.0, 1.0);
	
	if ( sizePct < .1 ) sizePct = 0;
	glTranslated(0, (int)numOfPixels/2, 0);
	glScalef(1, sizePct, 1);
	glTranslated(0, -(int)numOfPixels/2, 0);	
	
	
	
	
	
	
	//glBegin(GL_POINTS);
	for ( int i = 0; i<numOfPixels; i++ ) {
		pixels[i]->drawForDisplay(0,0, mainAlphaPct* stageAlphaPct);
	}
	//glEnd();
	//glTranslatef(-numOfPixels*.5, y, 0);

	ofPopMatrix();
	ofDisableAlphaBlending();
}


ofVec3f ofxTube::getPositionFor3D () {
	return pos3D;
}

