/*
 *  vLayerCosAnim.cpp
 *  LightField
 *
 *  Created by superscript_tower on 31/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "vLayerCosAnim.h"

vLayerCosAnim::vLayerCosAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
	step = 0;
}

void vLayerCosAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	
	
}

void vLayerCosAnim::launch(vector<ofxTube*> * tubes) {
	step = 0;
	sens = 1;
}


void vLayerCosAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 1.0, tube->nextTimeInactive , 0);
	tube->dumbPctTween.start();
	
	tube->setPixelAlpha(0, 1.0, 0.0); 
	//tube->setPixelAlpha(AbstractTubeAnimation::numOfTubePixels-1, 1.0, 0.0); 
	
}

void vLayerCosAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 0.0, tube->nextTimeActive * decayTimePct, 0);
	tube->dumbPctTween.start();
	
	
	
}

void vLayerCosAnim::onAnimationLoopEvent(int & a) {
	
	
	
}

void vLayerCosAnim::update () {
    AbstractTubeAnimation::update();
	
	
	count++;
	
	
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		
		ofxTube * tube = tubes->at(i);
		
		float pct = 1 + ( cos((int)(i*.5)+(count)*0.05) );
		step = (int)((AbstractTubeAnimation::numOfTubePixels -1) * pct / 2);
		
		//int step = (int)(tube->dumbPct * AbstractTubeAnimation::numOfTubePixels);
		
		int totalPixel = 36 * tube->sizePct;
		
		for ( int j= 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
			
			if ( j >= step-totalPixel && j <= step +totalPixel ) {
				
				int start = step-totalPixel;
				int stop = step+totalPixel;
				
				if ( start < 0 ) start = 0;
				if ( stop > AbstractTubeAnimation::numOfTubePixels ) stop = AbstractTubeAnimation::numOfTubePixels;
				
				float pct2 = ((float)j-(float)start-totalPixel) / totalPixel*2;
				
				//float alpha = (float)j / (float)step * tube->dumbPct;
				float alpha = (pct2 < .5 ) ? pct2 * 2 : 1.0 + ( 0.5 - pct2 ) *2;
				
								
				
				
				tube->setPixelAlpha(j, alpha*tube->dumbPct, 0.0); 
			} else {
				tube->setPixelAlpha(j, 0.0, 0.0); 
			}
			
		}
		
		
	}    
}

void vLayerCosAnim::quit () {
    AbstractTubeAnimation::quit();
}