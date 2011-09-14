/*
 *  vDualBlinkAnim.cpp
 *  ModularShip
 *
 *  Created by superscript_tower on 31/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "vDualBlinkAnim.h"


vDualBlinkAnim::vDualBlinkAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
}

void vDualBlinkAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	
	
}

void vDualBlinkAnim::launch(vector<ofxTube*> * tubes) {
	bIncrease = false;
}


void vDualBlinkAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 1.0, tube->nextTimeInactive , 0);
	tube->dumbPctTween.start();
	
}

void vDualBlinkAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 0.0, tube->nextTimeActive * decayTimePct, 0);
	tube->dumbPctTween.start();
	
	
	
}

void vDualBlinkAnim::onAnimationLoopEvent(int & a) {
	
}

void vDualBlinkAnim::update () {
    AbstractTubeAnimation::update();
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		
		ofxTube * tube = tubes->at(i);
		
		int middle = 8;
		int limit = 1 + (int)(tube->dumbPct * middle);
		int stepLimit = 1 + (int)(tube->dumbPct * 8);
		
		if ( (int)(ofGetFrameNum()* (1.0 - tube->dumbPct)) % 2 == 0 ) {
			bIncrease = !bIncrease;
		}
		
		
		
		bool bTubeIncrease = true;
		for ( int j= 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
			
			
			//int newLimit = (int)(tube->dumbPct * middle);
			//float alphaPct =  ( j % 2 == 0 )  ? 0.0 : 1.0;
			
					
			if ( bIncrease ) {
			
				if ( j<middle ) {
						
					float alpha = ((int)( j + ofGetFrameNum()* (1.0 - tube->dumbPct)) % limit == 0 ) ? 1.0 : 0.0;
						tube->setPixelAlpha(j, alpha*tube->dumbPct, 0.0); 
						
					} else {
						
					//	tube->pixels[i]->setPosition(0,middle-1, 0.0);
						tube->setPixelAlpha(j, 0.0, 0.0); 
					}
				
			} else {
				
				if ( j>middle ) {

					float alpha = ((int)( j + ofGetFrameNum()* (1.0 - tube->dumbPct)) % limit == 0 ) ? 1.0 : 0.0;
					tube->setPixelAlpha(j,alpha*tube->dumbPct, 0.0); 
				} else {
					
					tube->setPixelAlpha(j, 0.0, 0.0); 	
				}
				
			}
		}
	}
}
	

void vDualBlinkAnim::quit () {
    AbstractTubeAnimation::quit();
}