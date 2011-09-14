/*
 *  InverseCenteredPixelsAnim.cpp
 *  ModularShip
 *
 *  Created by superscript_tower on 25/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "InverseCenteredPixelsAnim.h"

InverseCenteredPixelsAnim::InverseCenteredPixelsAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
	limit = 8;
}

void InverseCenteredPixelsAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	middle = AbstractTubeAnimation::numOfTubePixels / 2;
}

void InverseCenteredPixelsAnim::launch(vector<ofxTube*> * tubes) {
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
		
		
		
		for ( int j = 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
			tube->setPixelAlpha(j, 0.0, 0.0); 
		}
	}
	//tube->setPixelAlpha(middle, 1.0, 0.0); 
	//tube->setPixelAlpha(middle-1, 1.0, 0.0); 
	
	
}

void InverseCenteredPixelsAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);	
	
	limit = tube->globalSizePct * 12;
	
	
	for ( int i= 0; i<AbstractTubeAnimation::numOfTubePixels; i++ ) {
		
		float time;
		
		
		
		if ( i<middle ) {
			
			if ( i<=limit) {
				
				time = tube->nextTimeActive +  (i*25)  *AbstractTubeAnimation::decayTimePct;
				tube->pixels[i]->setPosition(0,middle-i-1, time);
				tube->setPixelAlpha(i,time, 0.0); 
				
			}
			
		} else {
			
			if ( i >= AbstractTubeAnimation::numOfTubePixels - limit) {
				
				time =  tube->nextTimeActive +  ( (AbstractTubeAnimation::numOfTubePixels -i )*25)  *AbstractTubeAnimation::decayTimePct;
				tube->pixels[i]->setPosition(0, middle + (AbstractTubeAnimation::numOfTubePixels -i), time);
				tube->setPixelAlpha(i, time, 0.0); 
			}				   
			
		}
		
	}
	
	
}

void InverseCenteredPixelsAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	
	
	
	for ( int i= 0; i<AbstractTubeAnimation::numOfTubePixels; i++ ) {
		
		float time = 10.0;
		
		tube->setPixelAlpha(i, 0.0, 300.0); 
		
		if ( i<middle ) {
			
			if ( i<=limit) tube->pixels[i]->setPosition(0,0, time);
			
		} else {
			
			if ( i >= AbstractTubeAnimation::numOfTubePixels - limit) tube->pixels[i]->setPosition(0,AbstractTubeAnimation::numOfTubePixels-1, time);
			
		}					   
		
	}
	
}

void InverseCenteredPixelsAnim::onAnimationLoopEvent(int & a) {
	
}

void InverseCenteredPixelsAnim::update () {
    AbstractTubeAnimation::update();
}

void InverseCenteredPixelsAnim::quit () {
    AbstractTubeAnimation::quit();
}