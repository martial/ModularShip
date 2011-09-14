/*
 *  vLayerIncreaseAnim.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 30/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "vLayerIncreaseAnim.h"

vLayerIncreaseAnim::vLayerIncreaseAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
	step = 0;
}

void vLayerIncreaseAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	
	
}

void vLayerIncreaseAnim::launch(vector<ofxTube*> * tubes) {
	step = 0;
	sens = 1;
}


void vLayerIncreaseAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 1.0, tube->nextTimeInactive , 0);
	tube->dumbPctTween.start();
	
	tube->setPixelAlpha(0, 1.0, 0.0); 
	//tube->setPixelAlpha(AbstractTubeAnimation::numOfTubePixels-1, 1.0, 0.0); 
	
}

void vLayerIncreaseAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 0.0, tube->nextTimeActive * decayTimePct, 0);
	tube->dumbPctTween.start();
	
	
	
}

void vLayerIncreaseAnim::onAnimationLoopEvent(int & a) {
	
	
	
}

void vLayerIncreaseAnim::update () {
    AbstractTubeAnimation::update();
	
	step += sens;
	if ( step >= AbstractTubeAnimation::numOfTubePixels -1) {
		
		sens = -1;
	}
	
	if ( step <= 0) {
		
		sens = 1;
	}
	
	
	
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		
		ofxTube * tube = tubes->at(i);
		
		//int step = (int)(tube->dumbPct * AbstractTubeAnimation::numOfTubePixels);
		
		for ( int j= 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
			
			if ( j <= step ) {
				tube->setPixelAlpha(j, tube->dumbPct, 0.0); 
			} else {
				tube->setPixelAlpha(j, 0.0, 0.0); 
			}
			
		}
		
		
	}    
}

void vLayerIncreaseAnim::quit () {
    AbstractTubeAnimation::quit();
}