/*
 *  DualBlinAnim.cpp
 *  ModularShip
 *
 *  Created by superscript_tower on 25/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "DualBlinAnim.h"


DualBlinAnim::DualBlinAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
	limit = 8;
}

void DualBlinAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	middle = AbstractTubeAnimation::numOfTubePixels / 2;
}

void DualBlinAnim::launch(vector<ofxTube*> * tubes) {
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
		tube->dumbPctTween.setParameters(0, easingquint, ofxTween::easeOut, 0.0, 0.0, 0.0, 0.0);

		for ( int j = 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
			//tube->setPixelAlpha(j, 0.0, 0.0); 
		}
	}
	
	
	
}

void DualBlinAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);	
	
	tube->dumbPctTween.setParameters(0, easingquint, ofxTween::easeOut, 0.0, 1.0, 100.0 + tube->nextTimeActive * decayTimePct, 0);
	tube->dumbPctTween.start();
	
	
	
	
	
}

void DualBlinAnim::onTubeUpdateEvent(ofxTubeEvent & args) {
	
	
}

void DualBlinAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	
	
}

void DualBlinAnim::onAnimationLoopEvent(int & a) {
	
}

void DualBlinAnim::update () {
	
    AbstractTubeAnimation::update();
	

	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
				
		ofxTube * tube = tubes->at(i);
		
		
		
		
		bool bEnabled = true;
		for ( int j= 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
			limit = (int)(tube->dumbPct * 112);
			if (limit < 10 ) {
				tube->setPixelAlpha(j, 0.0, 0.0); 
			} else {
				if ( j % limit == 0) bEnabled = !bEnabled;
				tube->setPixelAlpha(j, bEnabled ? 1.0 : 0.0, 0.0); 
			}
			
		}
		
		
	}
}


void DualBlinAnim::quit() {
   	AbstractTubeAnimation::quit();

	
}
	
	
	
