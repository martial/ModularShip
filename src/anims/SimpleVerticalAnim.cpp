//
//  SimpleVerticalAnim.cpp
//  LightField
//
//  Created by Martial Geoffre on 03/05/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "SimpleVerticalAnim.h"


SimpleVerticalAnim::SimpleVerticalAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
}

void SimpleVerticalAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	
	
	
}

void SimpleVerticalAnim::launch(vector<ofxTube*> * tubes) {
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
		tube->changeSizePct(0, 0.0);
	}
}


void SimpleVerticalAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	tube->changeSizePct(tube->globalSizePct, 1);
	tube->setAllPixelAlpha(1.0, 0.0);
	
}

void SimpleVerticalAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	tube->changeSizePct(0, tube->nextTimeActive * decayTimePct * .5);
	//tube->setAllPixelAlpha(1.0, 0.0);
}

void SimpleVerticalAnim::onAnimationLoopEvent(int & a) {
	
}

void SimpleVerticalAnim::update () {
    AbstractTubeAnimation::update();
    
}

void SimpleVerticalAnim::quit () {
    AbstractTubeAnimation::quit();
}