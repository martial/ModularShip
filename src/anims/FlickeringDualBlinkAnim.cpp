/*
 *  FlickeringDualBlinkAnim.cpp
 *  ModularShip
 *
 *  Created by superscript_tower on 27/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "FlickeringDualBlinkAnim.h"

FlickeringDualBlinkAnim::FlickeringDualBlinkAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
	limit = 8;
}

void FlickeringDualBlinkAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	middle = AbstractTubeAnimation::numOfTubePixels / 2;
}

void FlickeringDualBlinkAnim::launch(vector<ofxTube*> * tubes) {
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
				
		for ( int j = 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
			tube->setPixelAlpha(j, 0.0, 0.0); 
		}
	}
		
}

void FlickeringDualBlinkAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);	
	
		
	tube->dumbPctTween.setParameters(0, easingquint, ofxTween::easeOut, 0, 1, tube->nextTimeActive * decayTimePct, 0);
	
	
	
	
	
	
}

void FlickeringDualBlinkAnim::onTubeUpdateEvent(ofxTubeEvent & args) {
	
	ofxTube * tube = tubes->at(args.id);
	
	limit = (int)(tube->dumbPct * 112);
	
	if (limit == 0 ) {
		for ( int i= 0; i<AbstractTubeAnimation::numOfTubePixels; i++ ) {
			tube->setPixelAlpha(i, 0.0, 0.0); 
		}
		return;
		
	}
	
	
	bool bEnabled = true;
	for ( int i= 0; i<AbstractTubeAnimation::numOfTubePixels; i++ ) {
		if ( i % limit != 0) bEnabled = !bEnabled;
		tube->setPixelAlpha(i, bEnabled ? 1.0 : 0.0, 0.0); 
	}
	
}

void FlickeringDualBlinkAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	
}

void FlickeringDualBlinkAnim::onAnimationLoopEvent(int & a) {
	
}

void FlickeringDualBlinkAnim::update () {
    AbstractTubeAnimation::update();
	
	
	
	for ( int i = 0; i < tubes->size(); i++ ) {
		
		
		
		ofxTube * tube = tubes->at(i);
		
		limit = (int)(tube->dumbPct * 112);
		
		
		if (limit == 0 ) {
			for ( int j= 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
				tube->setPixelAlpha(j, 0.0, 0.0); 
			}
			continue;
		}
		
		
		bool bEnabled = true;
		for ( int j= 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
			if ( j % limit == 0) bEnabled = !bEnabled;
			tube->setPixelAlpha(j, bEnabled ? 1.0 : 0.0, 0.0); 
		}
		
		
	}
}


void FlickeringDualBlinkAnim::quit() {
   	AbstractTubeAnimation::quit();
	
	
}
