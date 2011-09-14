/*
 *  CenteredPixelsReverseAnim.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 17/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "CenteredPixelsReverseAnim.h"


CenteredPixelsReverseAnim::CenteredPixelsReverseAnim () {
    CenteredPixelsReverseAnim::AbstractTubeAnimation();	
}

void CenteredPixelsReverseAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	middle = AbstractTubeAnimation::numOfTubePixels / 2;
}

void CenteredPixelsReverseAnim::launch() {
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
		
		
		
		for ( int j = 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
			tube->setPixelAlpha(j, 0.0, 0.0); 
		}
		
		tube->setPixelAlpha(0, 1.0, 0.0); 
		tube->setPixelAlpha(AbstractTubeAnimation::numOfTubePixels-1, 1.0, 0.0); 
	}
	
	
	
	
}

void CenteredPixelsReverseAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);	
	
	tube->setPixelAlpha(0, 1.0, 0.0); 
	tube->setPixelAlpha(AbstractTubeAnimation::numOfTubePixels-1, 1.0, 0.0); 
	
	tube->pixels[0]->setPosition(0,middle-1, 300);
	tube->pixels[AbstractTubeAnimation::numOfTubePixels-1]->setPosition(0,middle, 300);
	

	
}

void CenteredPixelsReverseAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
	tube->setPixelAlpha(0, 0.0, 300.0); 
	tube->setPixelAlpha(AbstractTubeAnimation::numOfTubePixels-1, 0.0, 300.0); 
	
	tube->pixels[0]->setPosition(0,0, 10.0);
	tube->pixels[AbstractTubeAnimation::numOfTubePixels-1]->setPosition(0,AbstractTubeAnimation::numOfTubePixels-1, 10.0);
	
	
}

void CenteredPixelsReverseAnim::onAnimationLoopEvent(int & a) {
	
}

void CenteredPixelsReverseAnim::update () {
    AbstractTubeAnimation::update();
}

void CenteredPixelsReverseAnim::quit() { 
	
}