/*
 *  vSimpleSideGradient.cpp
 *  ModularShip
 *
 *  Created by superscript_tower on 30/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "vSimpleSideGradient.h"

vSimpleSideGradient::vSimpleSideGradient () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
}

void vSimpleSideGradient::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	
	
}

void vSimpleSideGradient::launch(vector<ofxTube*> * tubes) {
	
}


void vSimpleSideGradient::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 1.0, tube->nextTimeInactive , 0);
	tube->dumbPctTween.start();
	
}

void vSimpleSideGradient::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 0.0, tube->nextTimeActive * decayTimePct, 0);
	tube->dumbPctTween.start();
	
	
	
}

void vSimpleSideGradient::onAnimationLoopEvent(int & a) {
	
}

void vSimpleSideGradient::update () {
    AbstractTubeAnimation::update();
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		
		ofxTube * tube = tubes->at(i);
		
		
		int limit = (int)(tube->dumbPct * AbstractTubeAnimation::numOfTubePixels);
		
		
		
		
		for ( int j= 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
						
			if ( j < limit ) {
				
				int index = j;
				int tubeIndex = ( i > 88 && tube->bVertical ) ? AbstractTubeAnimation::numOfTubePixels  -1 - j : j;
				float alpha = ( i > 88 && tube->bVertical ) ?  ((float)index / (float)limit) :  ((float)index / (float)limit);
				
				tube->setPixelAlpha(tubeIndex, alpha, 0.0); 
				
				} else {
					tube->setPixelAlpha(j, 0.0, 0.0); 
				}
				
				
			}
			
		
	}
	
    
}

void vSimpleSideGradient::quit () {
    AbstractTubeAnimation::quit();
}