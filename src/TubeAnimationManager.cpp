//
//  TubeAnimationManager.cpp
//  LightField
//
//  Created by Martial Geoffre on 03/05/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TubeAnimationManager.h"

/*
#include "SimpleVerticalAnim.h"
#include "SimpleVerticalPixelAnim.h"
#include "RainAnim.h"
#include "LayerAnim.h"
#include "simpleAnim.h"
#include "ofxSimpleGuiToo.h"
#include "CenteredPixelsAnim.h"
#include "PixelWaveAnim.h"
#include "RandomPixelBlowAnimation.h"
#include "InverseCenteredPixelsAnim.h"
#include "DualBlinAnim.h"
#include "GradientCenterAnim.h"
#include "SimpleCenterReverseAnim.h"
#include "SimpleCenterGradientAnim.h"
#include "SimpleCenterReverseGradientAnim.h"
 
 */

#include "vSimpleAnim.h"
#include "vSimpleOpacityAnim.h"
#include "vSimpleScaleCentered.h"
#include "vSimpleScaleCenteredGradient.h"
#include "vSimpleSideGradient.h"
#include "vDualPixelAnim.h"
#include "vDualPixelDecreaseAnim.h"
#include "vNoisyAnim.h"
#include "vCenterPixelPush.h"
#include "vLayerAnim.h"

#include "vLayerCosAnim.h"
#include "vDualBlinkAnim.h"


TubeAnimationManager::TubeAnimationManager () {
    currentAnimation = NULL;
	tubes = NULL;
    player = NULL;
	bLaunchNextFrame = false;
}

void TubeAnimationManager::setup (vector<ofxTube*> * tubes, ofxAnimPlayer * player) {
    
	this->tubes = tubes;
	
	currentAnimation = NULL;
	decayTimePct = 1.5;
	mode = 0;
	
	for ( int i=0; i<tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
		ofAddListener(tube->activeEvent,this,&TubeAnimationManager::onActiveEvent);
	}
	
	
	
	this->player = player;
	ofAddListener(this->player->animationLoopEvent, this, &TubeAnimationManager::onAnimationLoopEvent);
	
	setAnimations();
	//setCurrentAnimationById(animations.size()-1);
	setCurrentAnimationById(0);
	//gui.addSlider("Vertical", mode, 0, animations.size()-1);
	
}

void TubeAnimationManager::setAnimations() {
	
	
	/*
	SimpleAnim * simpleAnim = new SimpleAnim();
	SimpleVerticalAnim * simpleVertical = new SimpleVerticalAnim();
	//SimpleVerticalPixelAnim * simplePixelVertical = new SimpleVerticalPixelAnim();
	//RainAnim * rain = new RainAnim() ;
	LayerAnim * layerAnim = new LayerAnim();
	CenteredPixelsAnim * centered = new CenteredPixelsAnim();
	PixelWaveAnim * pixelWave = new PixelWaveAnim();
    RandomPixelBlowAnimation  * rdmBlow = new RandomPixelBlowAnimation();
	InverseCenteredPixelsAnim * inverse  = new InverseCenteredPixelsAnim();
	DualBlinAnim * dualBlink = new DualBlinAnim();
	GradientCenterAnim * gradientCenter = new GradientCenterAnim();
	
	
	SimpleCenterReverseAnim * simpleReverseAnim = new SimpleCenterReverseAnim();
	SimpleCenterGradientAnim * simpleCenterGradientAnim = new SimpleCenterGradientAnim();
	SimpleCenterReverseGradientAnim * simpleReverseGradientAnim = new SimpleCenterReverseGradientAnim();
	
	
	
	simpleAnim->init("simple anim", tubes);
	simpleVertical->init("simple vertical", tubes);
	
	
	simpleReverseAnim->init("Simple Center", tubes);
	simpleReverseGradientAnim->init("Simple Center Reverse", tubes);
	simpleCenterGradientAnim->init("Simple Center Gradient",tubes);
	
	
	//simplePixelVertical->init("simple pixel vertical", tubes);
	//rain->init("rain", tubes);
	layerAnim->init("Layer anim", tubes);
	centered->init("centered pixels", tubes);
	pixelWave->init("pixel wave", tubes);
	rdmBlow->init("rdm blow", tubes);
	inverse->init("inverse", tubes);
	dualBlink->init("Dual Blink", tubes);
	gradientCenter->init("Gradient Center", tubes);
	
	animations.push_back(simpleReverseAnim);
	animations.push_back(simpleCenterGradientAnim);
	animations.push_back(simpleReverseGradientAnim);
	
		
	animations.push_back(simpleAnim);
	animations.push_back(simpleVertical);
	//animations.push_back(simplePixelVertical);
	//animations.push_back(rain);
	animations.push_back(layerAnim);
	animations.push_back(centered);
	animations.push_back(pixelWave);
	animations.push_back(rdmBlow);
	animations.push_back(inverse);
	animations.push_back(dualBlink);
	animations.push_back(gradientCenter);
	 
	 */
	
	
	vSimpleAnim * simpleAnim = new vSimpleAnim();
	vSimpleOpacityAnim * simpleOpacityAnim = new vSimpleOpacityAnim();
	vSimpleScaleCentered * simpleScaleCentered = new vSimpleScaleCentered();
	vSimpleScaleCenteredGradient * simpleScaleCenteredGradient = new vSimpleScaleCenteredGradient();
	vSimpleSideGradient * simpleSideGradient = new vSimpleSideGradient();
	vDualPixelAnim * dualPixelAnim = new vDualPixelAnim();
	vDualPixelDecreaseAnim * dualPixelDecreaseAnim = new vDualPixelDecreaseAnim();
	vNoisyAnim * noisyAnim = new vNoisyAnim();
	vCenterPixelPush * pixelPush = new vCenterPixelPush();
	
	vLayerAnim * layerAnim = new vLayerAnim();
	vLayerCosAnim * layerCosAnim = new vLayerCosAnim();
	vDualBlinkAnim * dualBlinkAnim = new vDualBlinkAnim();
	
	simpleAnim->init("Simple", tubes);
	simpleOpacityAnim->init("Simple Opacity", tubes);
	simpleScaleCentered->init("Simple Scale Centered", tubes);
	simpleScaleCenteredGradient->init("Centered Scale Gradient", tubes);
    simpleSideGradient->init("Side Gradient", tubes);
	dualPixelAnim->init("Dual Pixel", tubes);
	dualPixelDecreaseAnim->init("Dual Decrease Pixel", tubes);
	noisyAnim->init("Random", tubes);
	pixelPush->init("Pixel Push", tubes);
	
	layerCosAnim->init("Layer Cosinus anim", tubes);
	dualBlinkAnim->init("Dual Blink", tubes);
	layerAnim->init("Layer Anim", tubes);

	
	animations.push_back(simpleAnim);
	animations.push_back(simpleOpacityAnim);
	animations.push_back(simpleScaleCentered);
	animations.push_back(simpleScaleCenteredGradient);
	animations.push_back(simpleSideGradient);
	animations.push_back(dualPixelAnim);
	animations.push_back(dualPixelDecreaseAnim);
	animations.push_back(noisyAnim);
	animations.push_back(pixelPush);
	animations.push_back(dualBlinkAnim);

	animations.push_back(layerCosAnim);
	animations.push_back(layerAnim);
	
	setCurrentAnimationById(5);
	
}

void TubeAnimationManager::update() {
    
    if (!currentAnimation ) return;
	
	if ( bLaunchNextFrame )  reset();
	
	/*
	if ( mode != oldMode ) {
		for ( int i=0; i<tubes->size(); i++ ) {
			ofxTube * tube = tubes->at(i);
			tube->reset();
		}
		setCurrentAnimationById(mode);
	}
	 */
	
	currentAnimation->decayTimePct = decayTimePct;
	currentAnimation->update();
	
	oldMode = mode;
	
	}

void TubeAnimationManager::setCurrentAnimationById(int num) {
    
	
	if ( num > animations.size() -1 ) return;
	if ( num < 0 ) return;
	
	mode = num;
	if ( currentAnimation  ) currentAnimation->quit();
	//currentAnimId = num;
	currentAnimation = NULL;
	currentAnimation = animations[num];
	
	bLaunchNextFrame = true;
   
	
}

void TubeAnimationManager::reset() {
    
	if (!tubes ) return;
	
	for ( int i=0; i<tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
		tube->reset();
	}
	
	
	if ( currentAnimation ) {
		currentAnimation->launch(tubes);
	}
	bLaunchNextFrame = false;
}


void TubeAnimationManager::increaseAnimations (bool bIncreasing){
	
	(bIncreasing) ? pushAnimation() : popAnimation();
}

void TubeAnimationManager::pushAnimation(){
	
	currentAnimId++;
	if ( currentAnimId > animations.size() -1 ) currentAnimId = animations.size() -1;
	setCurrentAnimationById(currentAnimId);
}
void TubeAnimationManager::popAnimation(){
	
	currentAnimId--;
	if ( currentAnimId < 0) currentAnimId = 0;
	setCurrentAnimationById(currentAnimId);
}

void TubeAnimationManager::onAnimationLoopEvent(int & a) {
	if (!currentAnimation ) return;
	currentAnimation->onAnimationLoopEvent(a);
}

void TubeAnimationManager::onActiveEvent(ofxTubeEvent & args) {
	
	ofxTube * tube = tubes->at(args.id);
	bool bActive = args.bActive;	
	
	if (!currentAnimation ) return;
	
	if ( bActive ) {
	
		currentAnimation->onAnimationStart(&args);
	} else {
		currentAnimation->onAnimationEnd(&args);
	}

}

void TubeAnimationManager::setDecayTimePct(float val) {
	decayTimePct = val;
	if ( currentAnimation ) currentAnimation->decayTimePct = val;
	
}