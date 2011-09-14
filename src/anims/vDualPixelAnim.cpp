/*
 *  vDualPixelAnim.cpp
 *  ModularShip
 *
 *  Created by superscript_tower on 30/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "vDualPixelAnim.h"


vDualPixelAnim::vDualPixelAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
}

void vDualPixelAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	
	
}

void vDualPixelAnim::launch(vector<ofxTube*> * tubes) {
	
}


void vDualPixelAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 1.0, tube->nextTimeInactive , 0);
	tube->dumbPctTween.start();
	
}

void vDualPixelAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 0.0, tube->nextTimeActive * decayTimePct, 0);
	tube->dumbPctTween.start();
	
	
	
}

void vDualPixelAnim::onAnimationLoopEvent(int & a) {
	
}

void vDualPixelAnim::update () {
    AbstractTubeAnimation::update();
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		
		ofxTube * tube = tubes->at(i);
		
		int middle = 56;
		int limit = (int)(tube->dumbPct * middle);
		int stepLimit = 1 + (int)(tube->dumbPct * 8);
		
		
		
		for ( int j= 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
			
			
			int newLimit = (int)(tube->dumbPct * middle);
			float alphaPct =  ( j % 2 == 0 )  ? 0.0 : 1.0;
						
			if ( j<middle ) {
				
				if ( j> middle - limit ) {
					
					//tube->pixels[i]->setPosition(0,0, time);
					
					//int index = middle -j;
					
					tube->setPixelAlpha(j, alphaPct, 0.0); 
				} else {
					//	tube->pixels[i]->setPosition(0,middle-1, 0.0);
					tube->setPixelAlpha(j, 0.0, 0.0); 
				}
				
			} else {
				
				if ( j < middle + limit) {
					
					
					tube->setPixelAlpha(j,alphaPct, 0.0); 
				}	else {
					
					tube->setPixelAlpha(j, 0.0, 0.0); 	
				}
				
			}
			
		}
		
	}
	
	
    
}

void vDualPixelAnim::quit () {
    AbstractTubeAnimation::quit();
}