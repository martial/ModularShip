/*
 *  vSimpleOpacityAnim.cpp
 *  ModularShip
 *
 *  Created by superscript_tower on 30/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "vSimpleOpacityAnim.h"



vSimpleOpacityAnim::vSimpleOpacityAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
}

void vSimpleOpacityAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	
	
}

void vSimpleOpacityAnim::launch(vector<ofxTube*> * tubes) {
		
}


void vSimpleOpacityAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	tube->changeSizePct(tube->globalSizePct,1.0);
	tube->setAllPixelAlpha(1.0, tube->nextTimeInactive);
	
		
}

void vSimpleOpacityAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	float time = tube->nextTimeActive * AbstractTubeAnimation::decayTimePct;
	tube->setAllPixelAlpha(0.0, time);
}

void vSimpleOpacityAnim::onAnimationLoopEvent(int & a) {
	
}

void vSimpleOpacityAnim::update () {
    AbstractTubeAnimation::update();
    
}

void vSimpleOpacityAnim::quit () {
    AbstractTubeAnimation::quit();
}