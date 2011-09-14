/*
 *  LayerAnim.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 07/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "LayerAnim.h"



LayerAnim::LayerAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
	
}

void LayerAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	middle = AbstractTubeAnimation::numOfTubePixels / 2;
}

void LayerAnim::launch(vector<ofxTube*> * tubes) {
	
	layerPos = 1;
	sens = 1;
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
		
		
		tube->dumbPctTween.setParameters(0, easingquint, ofxTween::easeOut, tube->dumbPct, 0.0, 0.0, 0.0);
		
		for ( int j=0; j< AbstractTubeAnimation::numOfTubePixels; j++ ) {
			tube->setPixelAlpha(j, 0.0, 0.0);
		}
	}

	
}


void LayerAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	
	// first we'll start a tween for the value increasing
	// 0 to middle
	
	//tube->timer.setup( tube->nextTimeActive *AbstractTubeAnimation::decayTimePct ), false,args->id);
	//tube->timer.startTimer();
	//ofAddListener(tube->timer.TIMER_REACHED, this, &LayerAnim::onTimerComplete);
	
	
	//tube->dumbPct = 0.0;
	tube->dumbPctTween.setParameters(0, easingquint, ofxTween::easeOut, 0.0, 1,  tube->nextTimeActive *AbstractTubeAnimation::decayTimePct, 0.0);
	
	
	
	
	
	
	
	
	
	/*
	
	tube->changeSizePct(1, 0.0);
	tube->setAllPixelAlpha(1.0, 0.0);
	

	for ( int j=0; j< AbstractTubeAnimation::numOfTubePixels; j++ ) {
		if ( j<layerPos ) {
		tube->pixels[j]->setAlphaPct(1.0, 0.0);
		} else {
		tube->pixels[j]->setAlphaPct(0.0, 0.0);
		}
	}
	
	tube->changeSizePct(0, tube->nextTimeActive *AbstractTubeAnimation::decayTimePct);
	tube->setAllPixelAlpha(0.0, tube->nextTimeActive *AbstractTubeAnimation::decayTimePct);

	*/
	
}

void LayerAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	
	//tube->changeSizePct(0, tube->nextTimeActive *AbstractTubeAnimation::decayTimePct);
	//tube->setAllPixelAlpha(0.0, tube->nextTimeActive *AbstractTubeAnimation::decayTimePct);
	
	
	
	//tube->changeSizePct(0, 2000);
}

void LayerAnim::onAnimationLoopEvent(int & a) {
		
}

void LayerAnim::onTimerComplete (int & id) {                                                                    
	
	//printf("Timer complete ! %d\n", id);
	
	//ofRemoveListener(tube->timer.TIMER_REACHED, this, &LayerAnim::onTimerComplete);
	
}

void LayerAnim::update () {
    AbstractTubeAnimation::update();	
	
	for ( int i = 0; i < tubes->size(); i++ ) {
				
		ofxTube * tube = tubes->at(i);
		
		float pct = ofClamp(tube->dumbPct, 0.0, 1.0);
		
		int limit = (int)(pct * middle * tube->sizePct);
		
		if ( pct == 1.0 ) {
			tube->dumbPctTween.setParameters(0, easingquint, ofxTween::easeOut, tube->dumbPct, 0.0, 0.0, 0);
			tube->dumbPctTween.start();
			
		}
		
		//int steps = 2 + (int)(tube->dumbPct * 112);
		
			
			for ( int j= 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
				
				 
				int index =  (j < middle )  ? middle -1 -j : j;
				int countFromMiddle =  (j < middle ) ? j : j - middle;
				
				
				float alpha =  ( (index + 1 + ofGetFrameNum()) % 2 == 0 ) ?  1 - pct  : 0.0;
				if ( countFromMiddle > limit || limit == 0.0) alpha = 0.0;
				tube->setPixelAlpha(index, alpha, 0.0); 
					
				}
		}
			
	
	    
}

void LayerAnim::quit () {
    AbstractTubeAnimation::quit();
}