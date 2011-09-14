/*
 *  lfLpd8Listener.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 19/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "lfLpdListener.h"

// Constructor
lfLpdListener::lfLpdListener(){
}

// Destructor
lfLpdListener::~lfLpdListener(){
}

void lfLpdListener::setup(ofxTubeManager * tubesManager, ofxTubeManager * tubesManagerPreview, ofxSoundManager * soundManager, superInterfacePanel * panel) {
	
	this->tubesManager = tubesManager;
	this->tubesManagerPreview = tubesManagerPreview;
	this->soundManager = soundManager;
	this->panel = panel;

	
	lastFrame = 0;
	
}

// Method that receives MIDI event messages.
void lfLpdListener::newMidiMessage(ofxMidiEventArgs& eventArgs){
	
	if (lastFrame == ofGetFrameNum() ) return;
	
	//printf("AHOU // ");
	cout << "byteOne = " << eventArgs.byteOne << endl;
	cout << "byteTwo[" << eventArgs.byteTwo << endl;
	
	Boolean isIncreasing = ( eventArgs.byteTwo < oldVal ) ? false : true;
	if (  eventArgs.byteTwo == 127 ) isIncreasing = true;
	if ( eventArgs.byteTwo == 0 ) isIncreasing = false;
	//cout << "val[" << val << endl;
	
	int val;
	float pct;
	bool sens;
	int anim;
	
	switch ( eventArgs.byteOne ) {
		
			
		// enable tap tempo
		case 0:
			tubesManager->player.tapTempoEnabled = !tubesManager->player.tapTempoEnabled;
			break;
			
		case 48:			
			tubesManager->player.pushFrame();
			break;
			
		case 4:
			 tubesManager->soundManager.opacitySoundEnabled = !tubesManager->soundManager.opacitySoundEnabled;
			break;
			
		case 5:
			tubesManager->soundManager.sizeSoundEnabled = !tubesManager->soundManager.sizeSoundEnabled;
			
			break;
			
			
		case 7:
			tubesManager->player.reverseMode = !tubesManager->player.reverseMode;
			tubesManagerPreview->player.reverseMode = !tubesManagerPreview->player.reverseMode;
			break;
			
			
		case 6:
			panel->bcolorTwoSoundEnabled = !panel->bcolorTwoSoundEnabled;
			break;
			
		case 1:
			if ( eventArgs.byteTwo != 127 )tubesManagerPreview->popAnimation();
			break;
			
		case 2:
			if ( eventArgs.byteTwo != 127 )tubesManagerPreview->pushAnimation();
			break;
			
		case 3:
			if ( eventArgs.byteTwo != 127 )tubesManager->setAnimation(tubesManagerPreview->currentAnimation);
			break;
		
			/*
		case 4:
			tubesManager->player.reverseMode = !tubesManager->player.reverseMode;
			break*/
		
		case 11:
			 sens =  ( eventArgs.byteTwo < 64 );
			tubesManager->player.toggleSens(sens);
			tubesManagerPreview->player.toggleSens(sens);
			//tubesManagerPreview->increaseAnimation(isIncreasing);

			break;
			
		case 8:
			anim = (int)( (127.0 - eventArgs.byteTwo ) * (float)(tubesManagerPreview->animData->animationsData.size() -1) / (float)127.0 );
			tubesManagerPreview->setAnimation(anim);
			//tubesManagerPreview->increaseAnimation(isIncreasing);
			
			break;
			
		case 12:
			pct = (float)eventArgs.byteTwo / (float)127.0;
			tubesManager->player.setSpeedPct(pct);
			tubesManagerPreview->player.setSpeedPct(pct);
			break;	
		
		case 13:
			tubesManager->vAnimationManager.setDecayTimePct( ((float)eventArgs.byteTwo * 4.0/ 127.0));
			break;
			
		case 15:
			tubesManager->colorManager.mode = (int)((eventArgs.byteTwo ) * 4 / 110);
			break;
			
			
			
	}
	lastFrame = ofGetFrameNum();
	oldVal = eventArgs.byteTwo;
	
	// Do the stuff you need to do with 
	// the ofxMidiEventArgs instance.
}