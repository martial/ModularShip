/*
 *  vLayerAnim.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 30/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "vLayerAnim.h"

vLayerAnim::vLayerAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
	step = 0;
}

void vLayerAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	
	
}

void vLayerAnim::launch(vector<ofxTube*> * tubes) {
	step = 0;
	sens = 1;
}


void vLayerAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 1.0, 100.0 , 0);
	tube->dumbPctTween.start();
	
	tube->setPixelAlpha(0, 1.0, 0.0); 
	//tube->setPixelAlpha(AbstractTubeAnimation::numOfTubePixels-1, 1.0, 0.0); 
	
}

void vLayerAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 0.0, tube->nextTimeActive * decayTimePct, 0);
	tube->dumbPctTween.start();
	
	
	
}

void vLayerAnim::onAnimationLoopEvent(int & a) {
	
	

}

void vLayerAnim::update () {
    AbstractTubeAnimation::update();
	
	
	
	int numOfPxEnabled = 8;
		
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		
		ofxTube * tube = tubes->at(i);
		
		
		int limit = (int)(tube->dumbPct * numOfPxEnabled);

		
		//int step = (int)(tube->dumbPct * AbstractTubeAnimation::numOfTubePixels);
		bool bEnabled = false;
		int ct = 0;
		
		for ( int j= 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
		
				
			float alpha = (bEnabled) ?  (tube->bActive ) ? ( (float)ct / (float)limit < 1.0 ) ? 0.0 : 1.0 : 0  : 0;
			tube->setPixelAlpha(j, alpha, 0.0); 
			
			
			
			ct++;
			if (ct >= numOfPxEnabled) {
				bEnabled = !bEnabled;
				ct =0;
				
			}
			
		}
		
		
	}    
}

void vLayerAnim::quit () {
    AbstractTubeAnimation::quit();
}