/*
 *  ShipMidiListener.cpp
 *  ModularShip
 *
 *  Created by Martial Geoffre on 10/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ShipMidiListener.h"

// Constructor
ShipMidiListener::ShipMidiListener(){
	tubesManager = NULL;
	tubesManagerPreview = NULL;
	soundManager = NULL;
	panel = NULL;
}

// Destructor
ShipMidiListener::~ShipMidiListener(){
}

void ShipMidiListener::setup(ofxTubeManager * tubesManager, ofxTubeManager * tubesManagerPreview, ofxSoundManager * soundManager,superInterfacePanel * panel) {
			
	this->tubesManager = tubesManager;
	this->tubesManagerPreview = tubesManagerPreview;
	this->soundManager = soundManager;
	this->panel = panel;
	
	lastFrame = 0;
	
}

// Method that receives MIDI event messages.
void ShipMidiListener::newMidiMessage(ofxMidiEventArgs& eventArgs){
	
	if ( ofGetFrameNum() == lastFrame ) return;
	
	cout << "byteOne = " << eventArgs.byteOne << endl;
	cout << "byteTwo[" << eventArgs.byteTwo << endl;
	
	Boolean isIncreasing = ( eventArgs.byteTwo < oldVal ) ? false : true;
	if (  eventArgs.byteTwo == 127 ) isIncreasing = true;
	if ( eventArgs.byteTwo == 0 ) isIncreasing = false;
	//cout << "val[" << val << endl;
	
	if ( eventArgs.byteOne >=36 &&  eventArgs.byteOne <= 51 ) {
		tubesManager->vAnimationManager.setCurrentAnimationById( eventArgs.byteOne - 36);
		return;
	}
	
	int val;
	float pct;
	switch ( eventArgs.byteOne ) {
			
		case 1:
			 pct = (float)eventArgs.byteTwo / (float)127.0;
			tubesManager->setStageOpacity(pct);
			break;	
		
		case 2:
			 pct = (float)eventArgs.byteTwo / (float)127.0;
			tubesManager->player.setSpeedPct(pct);
			tubesManagerPreview->player.setSpeedPct(pct);
			break;
			
		case 6:
			
			
			tubesManager->strob.bEnabled = ( eventArgs.byteTwo == 0 ) ? false : true;
			tubesManager->setFlickeringRange( 2 + ( (float) ( 127 - eventArgs.byteTwo ) * 10 / 127.0));
			tubesManager->enableFlickering (( eventArgs.byteTwo == 0 ) ? false : true);
			
			
		break;
			
		case 5:
			tubesManager->forceSimpleVertical( ( eventArgs.byteTwo == 0 ) ? false : true);
			tubesManager->rdmStrob.bEnabled = ( eventArgs.byteTwo == 0 ) ? false : true;
			tubesManager->rdmStrob.intensity =  (2 + (int)((float)(127-eventArgs.byteTwo) * 10.0 / 127.0));
			break;
			
		case 4:
			tubesManager->equalizer.bEnabled = ( eventArgs.byteTwo == 0 ) ? false : true;
			tubesManager->equalizer.mode =  (int)((eventArgs.byteTwo-1) * 2 / 127.0);
			break;
		
		case 3:
			
			tubesManager->enableFlickering(( eventArgs.byteTwo == 0 ) ? false : true);
			tubesManager->setFlickeringRange( 2 + ( (float) ( 127 - eventArgs.byteTwo ) * 10 / 127.0));
			break;
			
			
		case 14:
			val = 127- eventArgs.byteTwo;
			tubesManagerPreview->increaseAnimation(isIncreasing);
			break;
			
			
	
			
			
		case 11:
			//soundManager->setRange(eventArgs.byteTwo+1);
			break;
		
		case 12:
			soundManager->smooth = float(float(eventArgs.byteTwo)/127);
			break;
			
		case 40:
			tubesManager->soundManager.opacitySoundEnabled = !tubesManager->soundManager.opacitySoundEnabled;
			break;
			
		case 41:
			tubesManager->soundManager.sizeSoundEnabled = !tubesManager->soundManager.sizeSoundEnabled;

			break;

			
		case 42:
			tubesManager->soundManager.speedEnabled = !tubesManager->soundManager.speedEnabled;
			tubesManager->player.bSpeedByframe = tubesManager->player.bSpeedByframe;
			break;

			
		case 43:
			panel->bcolorTwoSoundEnabled = !panel->bcolorTwoSoundEnabled;
			break;
			
		case 36:
			tubesManager->setAnimation(tubesManagerPreview->currentAnimation);
			break;
			
			
		case 8:
			tubesManager->colorManager.mode = (int)((eventArgs.byteTwo ) * 4 / 127.0);
			break;
			
		case 9:
			
			
			tubesManager->vAnimationManager.increaseAnimations(isIncreasing);
			
			break;
			
		case 7:
			tubesManager->vAnimationManager.setDecayTimePct( ((float)eventArgs.byteTwo * 4.0/ 127.0));
			break;
			
	
			
			
			
			
	}
	
	lastFrame = ofGetFrameNum();
	oldVal = eventArgs.byteTwo;
	
	// Do the stuff you need to do with 
	// the ofxMidiEventArgs instance.
}