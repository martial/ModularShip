/*
 *  vCenterPixelPush.cpp
 *  ModularShip
 *
 *  Created by superscript_tower on 30/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "vCenterPixelPush.h"

vCenterPixelPush::vCenterPixelPush () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
}

void vCenterPixelPush::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	
	
}

void vCenterPixelPush::launch(vector<ofxTube*> * tubes) {
	
}


void vCenterPixelPush::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 1.0, tube->nextTimeInactive , 0);
	tube->dumbPctTween.start();
	
}

void vCenterPixelPush::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 0.0, tube->nextTimeActive * decayTimePct, 0);
	tube->dumbPctTween.start();
	
	
	
}

void vCenterPixelPush::onAnimationLoopEvent(int & a) {
	
}

void vCenterPixelPush::update () {
    AbstractTubeAnimation::update();
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		
		ofxTube * tube = tubes->at(i);
		
		int middle = 56;
		int limit = (int)(tube->dumbPct * middle);
		
		
		
		
		for ( int i= 0; i<AbstractTubeAnimation::numOfTubePixels; i++ ) {
			
			float time;
			
			
			
			if ( i<middle ) {
				
				if ( tube->bDumbPctIncrease ) {
				
					if ( i> middle - limit  ) {
					
						int index = middle -i;
						float alpha =  1.0 - ((float)i / (float)limit);
						tube->setPixelAlpha(i, alpha, 0.0); 
					} else {
					//	tube->pixels[i]->setPosition(0,middle-1, 0.0);
						tube->setPixelAlpha(i, 0.0, 0.0); 
					}
					
				} else {
					
					int index = middle - i ;
					float alpha =  1.0 - ((float)i /  ( (float)limit * tube->dumbPct));
					tube->setPixelAlpha(index, alpha, 0.0); 
					
				}
				
			} else {
				
				if ( tube->bDumbPctIncrease ) {

				
					if ( i < middle + limit) {
					
					
						int index = i - middle;
					
					//tube->pixels[i]->setPosition(0, AbstractTubeAnimation::numOfTubePixels -1 , time);
						float alpha =   ((float)index / (float)limit);
						tube->setPixelAlpha(i, alpha, 0.0); 
					}	else {
					//tube->pixels[i]->setPosition(0,i, 0.0);
						tube->setPixelAlpha(i, 0.0, 0.0); 	
					}
				
				} else {
					
					
					int index = i - middle;
					float alpha =   1.0 - ((float)index / ( (float)limit * tube->dumbPct));
					//alpha = .2;
					tube->setPixelAlpha(i, alpha, 0.0); 
					
					
					
					
				}
			
			
			}
		
		}
	
	}
	
	
    
}

void vCenterPixelPush::quit () {
    AbstractTubeAnimation::quit();
}