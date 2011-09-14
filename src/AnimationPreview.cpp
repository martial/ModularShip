/*
 *  AnimationPreview.cpp
 *  ModularShip
 *
 *  Created by superscript_tower on 26/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "AnimationPreview.h"

void AnimationPreview::setup(ofxTube * tube){
	
	this->tube = tube;
	
	fbo = new ofxFBOTexture();
	fbo->allocate(mainSettings::getNumOfTubePixels() * 10, 10);
	
	
}
void AnimationPreview::update() {
	
}
void AnimationPreview::draw(float x, float y) {
	
	//fbo->begin();
	tube->drawForPreview(0, 0);
	//fbo->end();
	
	//fbo->draw(x,y);
	
}
