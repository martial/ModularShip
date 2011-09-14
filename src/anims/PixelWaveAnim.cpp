/*
 *  PixelWaveAnim.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 17/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "PixelWaveAnim.h"


PixelWaveAnim::PixelWaveAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
}

void PixelWaveAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
}

void PixelWaveAnim::launch(vector<ofxTube*> * tube) {
	
	printf("launch pixel wave...");
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
		
		for ( int j = 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
			tube->setPixelAlpha(j, 0.0, 0.0); 
		}
	}
	
	//printf("launch pixel wave...");
	
}


void PixelWaveAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);

		
	int total = (int)(numOfTubePixels * tube->globalSizePct);
		for ( int j = 0; j<total; j++ ) {
			
			tube->setPixelAlpha(j, 1.0, 0.0, 0.0); 
			tube->pixels[j]->alphaPct = 1.0;
		}
	
	
	for ( int j = 0; j<numOfTubePixels; j++ ) {
		
		int index  =  ( tube->bVertical && tube->id > 88 ) ? numOfTubePixels-1-j : j;
		tube->setPixelAlpha(index, 0.0, 100.0 + tube->nextTimeActive / 1000 * ( j/4*10) * decayTimePct, tube->nextTimeActive / 100 * j/92 * decayTimePct); 
		
	}
	
	
}

void PixelWaveAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	
	
	
}

void PixelWaveAnim::onAnimationLoopEvent(int & a) {
	
}

void PixelWaveAnim::update () {
    AbstractTubeAnimation::update();
    
}

void PixelWaveAnim::quit() { 
	
}