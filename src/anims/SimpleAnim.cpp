/*
 *  SimpleAnim.cpp
 *  ModularShip
 *
 *  Created by Martial Geoffre on 11/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "SimpleAnim.h"



SimpleAnim::SimpleAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
}

void SimpleAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	
		
}

void SimpleAnim::launch(vector<ofxTube*> * tubes) {
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
		tube->changeSizePct(0, 0.0);
	
	}
	
}


void SimpleAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	tube->changeSizePct(tube->globalSizePct, 0.0);
	tube->setAllPixelAlpha(1.0, 0.0);
	
	
}

void SimpleAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	tube->changeSizePct(0, 0.0);
	tube->setAllPixelAlpha(0.0, 0.0);
}

void SimpleAnim::onAnimationLoopEvent(int & a) {
	
}

void SimpleAnim::update () {
    AbstractTubeAnimation::update();
    
}

void SimpleAnim::quit () {
    AbstractTubeAnimation::quit();
}