/*
 *  vNoisyAnim.cpp
 *  ModularShip
 *
 *  Created by superscript_tower on 30/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "vNoisyAnim.h"

vNoisyAnim::vNoisyAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
}

void vNoisyAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	
	
}

void vNoisyAnim::launch(vector<ofxTube*> * tubes) {
	
}


void vNoisyAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 1.0, tube->nextTimeInactive , 0);
	tube->dumbPctTween.start();
	
}

void vNoisyAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 0.0, tube->nextTimeActive * decayTimePct, 0);
	tube->dumbPctTween.start();
	
	
	
}

void vNoisyAnim::onAnimationLoopEvent(int & a) {
	
}

void vNoisyAnim::update () {
    AbstractTubeAnimation::update();
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		
		ofxTube * tube = tubes->at(i);
				
		for ( int j= 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
			
			
			float rdm = ofRandom(tube->dumbPct);
			float time = ofRandom(1) * 100.0 * tube->dumbPct;
			float delay = ofRandom(1) * 100;
			
			
			
			if ( rdm < .15 ) {
				
				tube->pixels[j]->setPosition(0,(int)ofRandom(AbstractTubeAnimation::numOfTubePixels-1), time);
				tube->setPixelAlpha(j, 1.0 * tube->dumbPct, time, ofRandom(1) * time); 
				} 	else {
					
				tube->setPixelAlpha(j, 0.0, time, ofRandom(1) * time); 
			}
		}
	
		
	}
	
	
    
}

void vNoisyAnim::quit () {
    AbstractTubeAnimation::quit();
}