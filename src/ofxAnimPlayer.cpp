/*
 *  ofxAnimPlayer.cpp
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 28/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxAnimPlayer.h"
#include "ofxSimpleGuiToo.h"

ofxAnimPlayer::ofxAnimPlayer () {
	currentAnimationData = NULL;
}

void ofxAnimPlayer::setup () {
	
	timeStep		= 0;
	currentFrame	= 0;
	sens			= 1;

	speed			= 50.0;
	realSpeed		= 50.0;
	speedAlpha		= 1.0;
	
	minSpeed		= 300.0;
	
	timeElapsedSpeed = 0.0;
	
	tapTempoEnabled =	false;
	bSpeedByframe	=	false;
	reverseMode		=	false; 
	framePct		=	0.0;
	
	id = 0;

}

frameData * ofxAnimPlayer::update () {
	
	if (!currentAnimationData ) return NULL;
	
	
	if ( tapTempoEnabled ) {
		return  getCurrentFrameData();
	}

	
	//sens = ( speed <= 0.0 ) ? -1 : 1;
	
	//if ( speed == 500 ) timeStep = ofGetElapsedTimeMillis();
	
	if ( bSpeedByframe ) {
		
		
		currentFrame = (int)(currentAnimationData->frames.size() * framePct);
		
		
		if ( currentFrame > currentAnimationData->frames.size() -1  && currentFrame != -1) {
			currentFrame = 0;
			ofNotifyEvent(animationLoopEvent, currentFrame, this);
		}
		
		if ( currentFrame < 0  ) {
			currentFrame = currentAnimationData->frames.size() -1 ;
			ofNotifyEvent(animationLoopEvent, currentFrame, this);
		}
		
		return getCurrentFrameData();
	}
	 
	 //printf("spped %f\n", currentAnimationData->speed);
	if ( ofGetElapsedTimeMillis() - timeStep > speed + speed *  (currentAnimationData->speed) ) {
		
	
		
		timeElapsedSpeed = ofGetElapsedTimeMillis() - timeStep;
		
		timeStep = ofGetElapsedTimeMillis();
		currentFrame += 1*sens;
		
	
				
		if ( currentFrame > currentAnimationData->frames.size() -1 && currentFrame != -1 ) {
			currentFrame = ( reverseMode ) ? currentAnimationData->frames.size() -1 : 0;
			if ( reverseMode ) sens = -1;
			
			ofNotifyEvent(animationLoopEvent, currentFrame, this);
		}
		
		if ( currentFrame < 0 || currentFrame == -1) {
			currentFrame = ( reverseMode ) ? 1 : currentAnimationData->frames.size() -1;

			if ( reverseMode ) sens = 1;

			ofNotifyEvent(animationLoopEvent, currentFrame, this);
		}
		
		
		
	}
	
	
	
	return getCurrentFrameData();
	
}

void ofxAnimPlayer::pushFrame()  {
	if (!currentAnimationData ) return;
	if ( !tapTempoEnabled ) return;
	
	currentFrame += 1*sens;
	
	
	if ( currentFrame > currentAnimationData->frames.size() -1 && currentFrame != -1 ) {
		currentFrame = ( reverseMode ) ? currentAnimationData->frames.size() -1 : 0;
		if ( reverseMode ) sens = -1;
	
	}
	
	if ( currentFrame < 0 || currentFrame == -1) {
		currentFrame = ( reverseMode ) ? 1 : currentAnimationData->frames.size() -1;
		if ( reverseMode ) sens = 1;
	}
	
	
}

void ofxAnimPlayer::setSpeedPct(float speedPct) {
	
	speed =  minSpeed * ( 1.0 - speedPct );
	return;
	
	if ( speedPct <= 0.5 ) {
		//if (!reverseMode ) sens = -1;
		speed =  (minSpeed * ( speedPct * 2));
	} else {
		//if (!reverseMode ) sens = 1;
		speed = minSpeed - (minSpeed  * (  ( speedPct - .5) * 2));
	}
	

		
	
}

void ofxAnimPlayer::resetFrame() {
		
	currentFrame = 0;
}

frameData * ofxAnimPlayer::getCurrentFrameData () {
	
	if(!currentAnimationData) return NULL;
	return currentAnimationData->frames[currentFrame];
	
}


void ofxAnimPlayer::setAnimation (animationData * animation) {
	currentFrame = 0;
	currentAnimationData = animation;
	
}



void ofxAnimPlayer::toggleSens(bool val) {
	
	sens = ( val ) ? 1 : -1;
	
}