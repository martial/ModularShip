//
//  AbstractTubeAnimation.cpp
//  LightField
//
//  Created by Martial Geoffre on 03/05/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "AbstractTubeAnimation.h"
#include "mainSettings.h"

AbstractTubeAnimation::AbstractTubeAnimation() {
    
	numOfTubePixels = mainSettings::getNumOfTubePixels();
    tubes = NULL;
}

void AbstractTubeAnimation::init(string name, vector<ofxTube*> * tubes) {
    
	this->tubes = tubes;
    this->name = name;
	decayTimePct = 200.0;
}


void AbstractTubeAnimation::launch(vector<ofxTube*> * tubes) {
    
	this->tubes = tubes;
}

void AbstractTubeAnimation::update() {
    
    
}

void AbstractTubeAnimation::onAnimationLoopEvent(int & a) {
	
}

void AbstractTubeAnimation::onAnimationStart(ofxTubeEvent * args) {
    
}

void AbstractTubeAnimation::onAnimationEnd(ofxTubeEvent * args) {
    

}


void AbstractTubeAnimation::quit() {
    
	
}

void AbstractTubeAnimation::setEstimatedAnimationTime(float time) {
    
    animationTime = time;
    
}