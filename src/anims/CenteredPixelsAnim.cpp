/*
 *  CenteredPixelsAnim.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 13/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "CenteredPixelsAnim.h"


CenteredPixelsAnim::CenteredPixelsAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
	limit = 8;
}

void CenteredPixelsAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	middle = AbstractTubeAnimation::numOfTubePixels / 2;
}

void CenteredPixelsAnim::launch(vector<ofxTube*> * tubes) {
	
		for ( int i = 0; i < (int)tubes->size(); i++ ) {
			ofxTube * tube = tubes->at(i);
	
		
	 
			for ( int j = 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
				tube->setPixelAlpha(j, 0.0, 0.0); 
			}
		}
		//tube->setPixelAlpha(middle, 1.0, 0.0); 
		//tube->setPixelAlpha(middle-1, 1.0, 0.0); 
	
		
}

void CenteredPixelsAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);	
	
	limit = tube->globalSizePct * 12;
	
	
	for ( int i= 0; i<AbstractTubeAnimation::numOfTubePixels; i++ ) {
		
		float time;
		
		
		
		if ( i<middle ) {
			
			if ( i<=limit) {
			
			int index =  i;
			
			time = 	( index * tube->nextTimeActive / limit ) * AbstractTubeAnimation::decayTimePct*.5;
				
			
			tube->pixels[middle-i-1]->setPosition(0,i, time);
			tube->setPixelAlpha(middle-i-1, time, 0.0); 
				
			}
			
		} else {
			
			if ( (i - middle) <= limit) {
			
			int index =  i - middle;
				
			time = 	( index * tube->nextTimeActive / limit ) * AbstractTubeAnimation::decayTimePct*.5;
			tube->pixels[i]->setPosition(0,AbstractTubeAnimation::numOfTubePixels + AbstractTubeAnimation::numOfTubePixels -1 - i - middle, time);
			tube->setPixelAlpha(i, time, 0.0); 
			}				   
			
		}
		
	}
	
		
}

void CenteredPixelsAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	
	
	
	for ( int i= 0; i<AbstractTubeAnimation::numOfTubePixels; i++ ) {
		
		float time = 10.0;
		
		tube->setPixelAlpha(i, 0.0, 0.0); 
		
		if ( i<middle ) {
			
			if ( i<=limit) tube->pixels[middle-i-1]->setPosition(0,middle, time);
			
		} else {
			
			if ( (i-middle) <=limit) tube->pixels[i]->setPosition(0,middle-1, time);
			
		}					   
															   
	}
								
}

void CenteredPixelsAnim::onAnimationLoopEvent(int & a) {
	
}

void CenteredPixelsAnim::update () {
    AbstractTubeAnimation::update();
}

void CenteredPixelsAnim::quit () {
    AbstractTubeAnimation::quit();
}
