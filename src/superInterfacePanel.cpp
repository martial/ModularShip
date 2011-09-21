/*
 *  superInterfacePanel.cpp
 *  MODULAR_SHIP
 *
 *  Created by Martial on 12/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "superInterfacePanel.h"
#include "ofxTubeManager.h"

void superInterfacePanel::setup(ofxTubeManager * tubesManager, ofxSoundManager * sndManager, guiView * view2D) {
	
	this->tubesManager = tubesManager;
	this->sndManager = sndManager;
	this->view2D = view2D;
	
	xmlSettings.loadFile("colors.xml");	
	globalColor.set(255,255,255);
	colorTwoIntensity = 1.0;
	bcolorTwoSoundEnabled = false;
	
	logo.loadImage("logo.png");
	
	fps.setup(256, 40, 60);
	
	superInterface.setup("");
	
	fft.setup(&superInterface, 16, &sndManager->filterRange, 34,20, 42,16);
	fpsComp.setup(&superInterface, &fps.fbo, 4,4, 4,4, "FPS");
	view2DFbo.setup(&superInterface, &view2D->fbo, 20,26, 32,32, "VIEW2D FBO");
	
	logoComp.setup(&superInterface, &logo, 42,4, 4,4, "LOGO");
	
	opacity.setup(&superInterface, tubesManager->soundManager.opacitySoundEnabled, "OPACITY", 0, 0, 8, 4);
	size.setup(&superInterface, tubesManager->soundManager.sizeSoundEnabled, "SIZE", 0, 4, 8, 4);
	tapTempo.setup(&superInterface, tubesManager->player.tapTempoEnabled, "TAP TEMPO", 0, 12, 8, 4);
	reverse.setup(&superInterface, tubesManager->player.reverseMode, "REVERSE", 0, 16, 8, 4);
	color.setup(&superInterface, bcolorTwoSoundEnabled, "COLOR", 0, 20, 8, 4);
	
	sequencerEnabled.setup(&superInterface, tubesManager->bSequencerMode, "SEQUENCER", 0, 42, 8, 4);
	
	speed.setup(&superInterface, &tubesManager->player.speed, 8, 0, 16, 2, 0.0, 200.0, "SPEED");
	vertical.setup(&superInterface, &tubesManager->vAnimationManager.mode, 8, 4, 16, 2, 0.0, tubesManager->vAnimationManager.animations.size()-1, "VERTICAL MODE");
			  
	decay.setup(&superInterface, &tubesManager->vAnimationManager.decayTimePct, 8, 16, 16, 2, 0.0, 4.0, "DECAY");
			  
	colorMode.setup(&superInterface, &tubesManager->colorManager.mode, 8, 16, 16, 2, 0, 5, "COLOR MODE");
	
	animNames.setup(&superInterface, 52, 12, "ANIMATION:");
	
	superInterface.addComponent(&logoComp, 0);
	superInterface.addComponent(&fpsComp, 0);
	superInterface.addComponent(&fft, 0);
	superInterface.addComponent(&view2DFbo, 0);
	superInterface.addComponent(&opacity, 0);
	superInterface.addComponent(&size, 0);
	superInterface.addComponent(&tapTempo, 0);
	superInterface.addComponent(&reverse, 0);
	superInterface.addComponent(&color, 0);
	superInterface.addComponent(&sequencerEnabled, 0);
			  
	superInterface.addComponent(&speed, 0);
	superInterface.addComponent(&vertical, 0);
	superInterface.addComponent(&decay, 0);
	superInterface.addComponent(&colorMode, 0);
	
	superInterface.addComponent(&animNames, 0);
	
	
	
	colorMode.enableAutoUpdate(true);
	
	loadXML();
	
	/*
	
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
	
	 */
		
	
	
	
}

void superInterfacePanel::loadXML () {
	
	xmlSettings.pushTag("colors");
	
	numOfPanels = xmlSettings.getNumTags("panel");
	colors.reserve(numOfPanels);
	colorsTemp.reserve(numOfPanels);
	
	for ( int i = 0; i < numOfPanels; i++ ) {
		
		ofLog(OF_LOG_NOTICE ,"go go go...");
		
		xmlSettings.pushTag("panel", i);
		
		ofColor color;
		color.set(255, 255, 255);
		colors.push_back(color);
		colorsTemp.push_back(color);
		
		string name = ( i != numOfPanels-1 ) ? "Gradient " + ofToString(i) : "All Colors";
		ofColor * targetColor = ( i != numOfPanels-1 ) ? &colors[i] : &globalColor;
		
		superInterfacePalettePicker * palette = new superInterfacePalettePicker();
		palette->setup(&superInterface, targetColor, name, 24, i*4, 32, 6);
		superInterface.addComponent(palette, 0);
		
		ofAddListener(palette->onClickEvent, this, &superInterfacePanel::onClickHandler);
		pickers.push_back(palette);
		
		int numOfColors = xmlSettings.getNumTags("color");
		
		for ( int j=0; j<numOfColors;j++) {
			
			ofColor colorPalette;
			int r = xmlSettings.getAttribute("color", "r", 0, j);
			int g = xmlSettings.getAttribute("color", "g", 0, j);
			int b = xmlSettings.getAttribute("color", "b", 0, j);
			colorPalette.set(r, g, b);
			palette->addColor(colorPalette);
			
		}
		xmlSettings.popTag();
	}
	
}

void superInterfacePanel::onClickHandler(string & label) {
	
	if ( label=="All Colors" ) {
		allColorsEnabled = true;
	} else {
		allColorsEnabled = false;
	}
	
}

void superInterfacePanel::update () {
	
	
	fft.updateValues(sndManager->getSpectrum());
	
	colorTwoIntensity = (bcolorTwoSoundEnabled) ? sndManager->left[64] : 1.0;
	
	colorsTemp[0] = colors[0];
	colorsTemp[2] = colors[2];
	
	colorsTemp[1].r = colors[0].r + ((colors[1].r - colors[0].r) * colorTwoIntensity);
	colorsTemp[1].g = colors[0].g + ((colors[1].g - colors[0].g) * colorTwoIntensity);
	colorsTemp[1].b = colors[0].b + ((colors[1].b - colors[0].b) * colorTwoIntensity);
	
	
	
	if ( allColorsEnabled ) {
		
		for ( int i=0; i<pickers.size()-1;i++) {
			//colors[i] = globalColor;
			ofColor ahou;
			ahou.set(globalColor.r, globalColor.g, globalColor.b);
			pickers[i]->setColor(ahou);
		}
	}
	
	superInterface.update();
	
	if ( tubesManager->vAnimationManager.currentAnimation ) vertical.txtLabel.extraText = tubesManager->vAnimationManager.currentAnimation->name;
	
	animNames.extraText = " " + tubesManager->player.currentAnimationData->name;
	
}



void superInterfacePanel::draw() {
	fps.draw(0, 0, 256, 40, true);
	superInterface.draw();
}

