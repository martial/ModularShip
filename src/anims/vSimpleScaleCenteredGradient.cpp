/*
 *  vSimpleScaleCenteredGradient.cpp
 *  ModularShip
 *
 *  Created by superscript_tower on 30/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "vSimpleScaleCenteredGradient.h"

vSimpleScaleCenteredGradient::vSimpleScaleCenteredGradient () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
}

void vSimpleScaleCenteredGradient::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	
	
}

void vSimpleScaleCenteredGradient::launch(vector<ofxTube*> * tubes) {
	
}


void vSimpleScaleCenteredGradient::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 1.0, tube->nextTimeInactive , 0);
	tube->dumbPctTween.start();
	
}

void vSimpleScaleCenteredGradient::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 0.0, tube->nextTimeActive * decayTimePct, 0);
	tube->dumbPctTween.start();
	
	
	
}

void vSimpleScaleCenteredGradient::onAnimationLoopEvent(int & a) {
	
}

void vSimpleScaleCenteredGradient::update () {
    AbstractTubeAnimation::update();
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		
		ofxTube * tube = tubes->at(i);
		
		
		//float pct = ( tube->bDumbPctIncrease ) ?  tube->dumbPct : 1.0 - tube->dumbPct;
		
		int middle = 56;
		int limit = (int)(tube->dumbPct * middle);
		
		
		
		
		for ( int i= 0; i<AbstractTubeAnimation::numOfTubePixels; i++ ) {
			
			float time;
				
			
			if ( i<middle ) {
				
				if ( i> middle - limit ) {
					
					//tube->pixels[i]->setPosition(0,0, time);
					
					int index = middle -i;
					
					tube->setPixelAlpha(i, 1.0 - ((float)index*.8 / (float)limit), 0.0); 
				} else {
					//	tube->pixels[i]->setPosition(0,middle-1, 0.0);
					tube->setPixelAlpha(i, 0.0, 0.0); 
				}
				
			} else {
				
				if ( i < middle + limit) {
					
					
					int index = i - middle;
					
					//tube->pixels[i]->setPosition(0, AbstractTubeAnimation::numOfTubePixels -1 , time);
					tube->setPixelAlpha(i,1.0 - ((float)index*.8 / (float)limit), 0.0); 
				}	else {
					//tube->pixels[i]->setPosition(0,i, 0.0);
					tube->setPixelAlpha(i, 0.0, 0.0); 	
				}
				
			}
			
		}
		
	}
	
    
}

void vSimpleScaleCenteredGradient::quit () {
    AbstractTubeAnimation::quit();
}