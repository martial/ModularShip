/*
 *  RandomPixelBlowAnimation.cpp
 *  ModularShip
 *
 *  Created by Martial Geoffre on 20/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "RandomPixelBlowAnimation.h"

RandomPixelBlowAnimation::RandomPixelBlowAnimation () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
}

void RandomPixelBlowAnimation::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	
	
}

void RandomPixelBlowAnimation::launch(vector<ofxTube*> * tubes) {
	
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
				
		for ( int j = 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
			tube->setPixelAlpha(j, 0.0, 0.0); 
		}
	}
	
}


void RandomPixelBlowAnimation::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	
	
	float delay;
	float time;
	for ( int j = 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {		
		float rdm = ofRandom(1);
		
		if ( rdm < .15 ) {
			
			time = ofRandom(1) * (tube->nextTimeActive) -100;
			delay = ofRandom(1) * 100;
			
			tube->setPixelAlpha(j, 1.0, time, delay); 
		} 			
	}
	tube->timer.setup( (time + delay) * .5 , false,args->id);
	tube->timer.startTimer();
	ofAddListener(tube->timer.TIMER_REACHED, this, &RandomPixelBlowAnimation::onTimerComplete);
}

void RandomPixelBlowAnimation::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	
}

void RandomPixelBlowAnimation::onTimerComplete (int & id) {                                                                    
	
	//printf("Timer complete ! %d\n", id);
	
	ofxTube * tube = tubes->at(id);	
	for ( int j = 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
		tube->setPixelAlpha(j, 0.0, 100.0 * ofRandom(8) * AbstractTubeAnimation::decayTimePct , 0.0); 
	}
	ofRemoveListener(tube->timer.TIMER_REACHED, this, &RandomPixelBlowAnimation::onTimerComplete);
	
}

void RandomPixelBlowAnimation::onAnimationLoopEvent(int & a) {
	
}

void RandomPixelBlowAnimation::update () {
    AbstractTubeAnimation::update();
    
}

void RandomPixelBlowAnimation::quit () {
    AbstractTubeAnimation::quit();
}