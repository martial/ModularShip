/*
 *  GradientCenterAnim.cpp
 *  ModularShip
 *
 *  Created by superscript_tower on 25/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "GradientCenterAnim.h"

GradientCenterAnim::GradientCenterAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
	limit = 8;
}

void GradientCenterAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	middle = AbstractTubeAnimation::numOfTubePixels / 2;
}

void GradientCenterAnim::launch(vector<ofxTube*> * tubes) {
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
		for ( int j = 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
			tube->setPixelAlpha(j, 0.0, 0.0); 
		}
		tube->changeSizePct(0, 0.0);
	}
}

void GradientCenterAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);	
	
	float time = tube->nextTimeActive * .5;
	
	
	for ( int j = 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
		float alpha = ( j <= middle ) ?  (  (float)j / (float)middle ) : ((float) AbstractTubeAnimation::numOfTubePixels - (float) j) / (float)middle ;
		tube->setPixelAlpha(j, alpha, time * decayTimePct * alpha); 
		
	}
	tube->changeSizePct(1, time * decayTimePct);
	
	tube->timer.setup( time * decayTimePct, false,args->id);
	tube->timer.startTimer();
	ofAddListener(tube->timer.TIMER_REACHED, this, &GradientCenterAnim::onTimerComplete);
	
	
	
}

void GradientCenterAnim::onTimerComplete (int & id) {                                                                    
	
	//printf("Timer complete ! %d\n", id);
	
	ofxTube * tube = tubes->at(id);	
	float time = tube->nextTimeActive * .5;
	for ( int j = 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
		tube->setPixelAlpha(j, 0.0, time * decayTimePct , 0.0); 
	}
	tube->changeSizePct(0, time * decayTimePct);
	
	ofRemoveListener(tube->timer.TIMER_REACHED, this, &GradientCenterAnim::onTimerComplete);
	
	printf("animation complete..\n");
}



void GradientCenterAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);

	
	
}

void GradientCenterAnim::onAnimationLoopEvent(int & a) {
	
}

void GradientCenterAnim::update () {
    AbstractTubeAnimation::update();
		
}


void GradientCenterAnim::quit() {
   	AbstractTubeAnimation::quit();
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
		ofRemoveListener(tube->timer.TIMER_REACHED, this, &GradientCenterAnim::onTimerComplete);
	}
	
	
}
