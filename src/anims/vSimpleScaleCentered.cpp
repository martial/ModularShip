/*
 *  vSimpleScaleCentered.cpp
 *  ModularShip
 *
 *  Created by superscript_tower on 30/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "vSimpleScaleCentered.h"


vSimpleScaleCentered::vSimpleScaleCentered () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
}

void vSimpleScaleCentered::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	
	
}

void vSimpleScaleCentered::launch(vector<ofxTube*> * tubes) {
	
}


void vSimpleScaleCentered::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	tube->changeSizePct(tube->globalSizePct, 0.0);
	tube->setAllPixelAlpha(1.0, 0.0);
	
	
}

void vSimpleScaleCentered::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	float time = tube->nextTimeActive * AbstractTubeAnimation::decayTimePct;
	tube->changeSizePct(0.0, time);
	tube->setAllPixelAlpha(1.0, time);
	
}

void vSimpleScaleCentered::onAnimationLoopEvent(int & a) {
	
}

void vSimpleScaleCentered::update () {
    AbstractTubeAnimation::update();
    
}

void vSimpleScaleCentered::quit () {
    AbstractTubeAnimation::quit();
}