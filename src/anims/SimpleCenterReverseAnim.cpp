/*
 *  SimpleCenterReverseAnim.cpp
 *  LightField
 *
 *  Created by superscript_tower on 29/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "SimpleCenterReverseAnim.h"

SimpleCenterReverseAnim::SimpleCenterReverseAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
}

void SimpleCenterReverseAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
}

void SimpleCenterReverseAnim::launch() {
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
		
		for ( int j = 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
			tube->setPixelAlpha(j, 0.0, 0.0); 
		}
	}
}


void SimpleCenterReverseAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	
	
	tube->dumbPctTween.setParameters(0, easingquint, ofxTween::easeOut, tube->dumbPct, 1.0, 100.0 + tube->nextTimeActive * decayTimePct, 0);
	tube->dumbPctTween.start();
}

void SimpleCenterReverseAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
}

void SimpleCenterReverseAnim::onAnimationLoopEvent(int & a) {
	
}

void SimpleCenterReverseAnim::update () {
    AbstractTubeAnimation::update();
	
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		
		ofxTube * tube = tubes->at(i);
		
		int middle = 56;
		int limit = (int)(tube->dumbPct * middle);
		
		
		
		
		for ( int i= 0; i<AbstractTubeAnimation::numOfTubePixels; i++ ) {
			
			float time;
			
			
			if ( tube->dumbPct == 1.0 ) {
				tube->dumbPctTween.setParameters(0, easingquint, ofxTween::easeOut, tube->dumbPct, 0.0, 0.0, 0);
				tube->dumbPctTween.start();
				tube->setPixelAlpha(i, 0.0, 0.0); 
				continue;
			}
			
			
			if ( i<middle ) {
				
				if ( i> middle - limit ) {
					
					//tube->pixels[i]->setPosition(0,0, time);
					
					int index = middle -i;
					
					tube->setPixelAlpha(i, 1.0, 0.0); 
				} else {
					//	tube->pixels[i]->setPosition(0,middle-1, 0.0);
					tube->setPixelAlpha(i, 0.0, 0.0); 
				}
				
			} else {
				
				if ( i < middle + limit) {
					
					
					int index = i - middle;

					//tube->pixels[i]->setPosition(0, AbstractTubeAnimation::numOfTubePixels -1 , time);
					tube->setPixelAlpha(i,1.0, 0.0); 
				}	else {
					//tube->pixels[i]->setPosition(0,i, 0.0);
					tube->setPixelAlpha(i, 0.0, 0.0); 	
				}
				
			}
			
		}
		
	}
    
}

void SimpleCenterReverseAnim::quit() { 
	
}