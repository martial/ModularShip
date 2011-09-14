/*
 *  vDualPixelAnim.cpp
 *  ModularShip
 *
 *  Created by superscript_tower on 30/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "vDualPixelDecreaseAnim.h"

vDualPixelDecreaseAnim::vDualPixelDecreaseAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
}

void vDualPixelDecreaseAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	
	
}

void vDualPixelDecreaseAnim::launch(vector<ofxTube*> * tubes) {
	
}


void vDualPixelDecreaseAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 1.0, tube->nextTimeInactive , 0);
	tube->dumbPctTween.start();
	
}

void vDualPixelDecreaseAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 0.0, tube->nextTimeActive * decayTimePct, 0);
	tube->dumbPctTween.start();
	
	
	
}

void vDualPixelDecreaseAnim::onAnimationLoopEvent(int & a) {
	
}

void vDualPixelDecreaseAnim::update () {
    AbstractTubeAnimation::update();
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		
		ofxTube * tube = tubes->at(i);
		
		int middle = 56;
		int limit = (int)(tube->dumbPct * middle);
		int stepLimit = 1 + (int)(tube->dumbPct * 8);
		
		
		
		for ( int j= 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
			
			
			int newLimit = (int)(tube->dumbPct * middle);
			float alphaPct =  ( j % stepLimit == 0 )  ? 0.0 : 1.0;
			if ( tube->dumbPct == 1.0)  alphaPct = 1.0;
			//printf("alpha ? %f\n", alpha);
			
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
					
					
					//int index = j - middle;
					//alphaPct =  ( j % stepLimit == 0)  ? 1.0 : 0.0;
					tube->setPixelAlpha(j,alphaPct, 0.0); 
				}	else {
					
					tube->setPixelAlpha(j, 0.0, 0.0); 	
				}
				
			}
			
		}
		
	}
	
	
    
}

void vDualPixelDecreaseAnim::quit () {
    AbstractTubeAnimation::quit();
}