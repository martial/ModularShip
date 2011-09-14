/*
 *  guiCreator.cpp
 *  ModularShip
 *
 *  Created by Martial Geoffre on 11/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "guiCreator.h"
#include "ofxSimpleGuiToo.h"
#include "ofxSimpleGuiMultiToggle.h"



void guiCreator::setup(ofxTubeManager * tubesManager, ofxSoundManager * sndManager, guiPanel * panel) {
	
	this->tubesManager = tubesManager;
	this->sndManager = sndManager;
	this->panel = panel;

		
	gui.addFboContent("Equalizer", sndManager->fboEqualizer);
	
	//gui.addSlider("Freq range", sndManager->range, sndManager->minRange,sndManager->maxRange);
	//gui.addSlider("Smooth",  sndManager->smooth, 0.0f, 1.0f);
	//gui.addSlider("Filter Range",  sndManager->filterRange, 0, 4);
	
	//gui.addSlider("Sound dispatch", tubesManager->soundManager.mode, 0, 2);
	gui.addToggle("Opacity -> sound" , tubesManager->soundManager.opacitySoundEnabled);
	gui.addToggle("Size -> sound" , tubesManager->soundManager.sizeSoundEnabled);
	gui.addToggle("Color -> sound" , panel->bcolorTwoSoundEnabled);
	//gui.addToggle("Reverse Mode -> sound" , tubesManager->soundManager.speedEnabled);

	gui.addToggle("Reverse Mode" , tubesManager->player.reverseMode);
	
	gui.addToggle("Tap tempo" ,tubesManager->player.tapTempoEnabled);
		
	gui.addTitle("", 80);
	
	//gui.addSlider("Signal",  sndManager->signal, 1.0f, 10.0f);
    //gui.addSlider("linearEQIntercept",  sndManager->linearEQIntercept, 0.0f, 2.0f);
   // gui.addSlider("linearEQSlope",  sndManager->linearEQSlope, 0.0f, 2.0f);
	
	gui.addSlider("Speed", tubesManager->player.speed, 0, 200);
	verticalSlider = &gui.addSlider("Vertical", tubesManager->vAnimationManager.mode, 0, tubesManager->vAnimationManager.animations.size()-1);
	gui.addSlider("Decay Pct", tubesManager->vAnimationManager.decayTimePct, 0.0, 6.0);
	gui.addSlider("Color mode", tubesManager->colorManager.mode, 0, 5);
	
	/*
	gui.addSlider("panel 1 rot x", tubesManager->panelOneRotX, 0, 180);
	gui.addSlider("panel 1 rot y", tubesManager->panelOneRotY, 0, 180);
	gui.addSlider("panel 2 rot x", tubesManager->panelTwoRotX, 0, 180);
	gui.addSlider("panel 2 rot y", tubesManager->panelTwoRotY, 0, 180);
	
	
	ofxSimpleGuiMultiToggle * toggle = &gui.addMultiToggle("ahou");
	
	bool1 = false;
	bool2 = true;
	bool3 = false;
	bool4 = true;
	
	toggle->addToggleButton("ahou", bool1);
	toggle->addToggleButton("", bool2);
	toggle->addToggleButton("", bool3);
	toggle->addToggleButton("", bool4);
	 */
	

}

void guiCreator::update () {
	
	if ( tubesManager->vAnimationManager.currentAnimation ) verticalSlider->name = tubesManager->vAnimationManager.currentAnimation->name;
	
}
