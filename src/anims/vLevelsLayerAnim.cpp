/*
 *  vLevelsLayerAnim.cpp
 *  LightField
 *
 *  Created by superscript_tower on 31/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "vLevelsLayerAnim.h"
#include "mainSettings.h"

vLevelsLayerAnim::vLevelsLayerAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
	step = 0;
}

void vLevelsLayerAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	
	
}

void vLevelsLayerAnim::launch(vector<ofxTube*> * tubes) {
	step = 0;
	sens = 1;
}


void vLevelsLayerAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 1.0, tube->nextTimeInactive , 0);
	tube->dumbPctTween.start();
	
	tube->setPixelAlpha(0, 1.0, 0.0); 
	//tube->setPixelAlpha(AbstractTubeAnimation::numOfTubePixels-1, 1.0, 0.0); 
	
}

void vLevelsLayerAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	tube->dumbPctTween.setParameters(0, quint, ofxTween::easeOut, tube->dumbPct, 0.0, tube->nextTimeActive * decayTimePct, 0);
	tube->dumbPctTween.start();
	
	
	
}

void vLevelsLayerAnim::onAnimationLoopEvent(int & a) {
	
	
	
}

void vLevelsLayerAnim::update () {
    AbstractTubeAnimation::update();
	
	
	count++;
	
	ofPoint coords;
	coords.set(mainSettings::getGridSize().x, mainSettings::getGridSize().y, 0);
	
	
		
		
		
			
		//int step = (int)(tube->dumbPct * AbstractTubeAnimation::numOfTubePixels);
		float step = 0;
		for ( int j = 0; j < coords.y; j++) {
			
			int level = (int)(step * AbstractTubeAnimation::numOfTubePixels / coords.y);
			for ( int i = 0; i < coords.x; i++) {
				
				ofxTube * tube = tubes->at(i * coords.y + j);
				for ( int z= 0; z<AbstractTubeAnimation::numOfTubePixels; z++ ) {
					if ( z== (int)(level* tube->dumbPct) ) {
					tube->setPixelAlpha(z, tube->dumbPct, 0.0); 	
					} else {
						tube->setPixelAlpha(z, 0.0, 0.0); 
					}
				}
				
				
			}
			if ( j< (int)(coords.y/2)) {
				step+=2;
			} else {
				step-=2;
			}
			//step++;	
		}
		
	
}

void vLevelsLayerAnim::quit () {
    AbstractTubeAnimation::quit();
}