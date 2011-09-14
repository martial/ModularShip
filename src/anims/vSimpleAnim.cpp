/*
 *  vSimpleAnim.cpp
 *  ModularShip
 *
 *  Created by superscript_tower on 30/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "vSimpleAnim.h"



vSimpleAnim::vSimpleAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
}

void vSimpleAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	
	
}

void vSimpleAnim::launch(vector<ofxTube*> * tubes) {
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
		tube->changeSizePct(0, 0.0);
	}
	
}


void vSimpleAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	tube->changeSizePct(tube->globalSizePct, 0.0);
	tube->setAllPixelAlpha(1.0, 0.0);
	
	
}

void vSimpleAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	tube->changeSizePct(0, 0.0);
	tube->setAllPixelAlpha(0.0, 0.0);
}

void vSimpleAnim::onAnimationLoopEvent(int & a) {
	
}

void vSimpleAnim::update () {
    AbstractTubeAnimation::update();
    
}

void vSimpleAnim::quit () {
    AbstractTubeAnimation::quit();
}