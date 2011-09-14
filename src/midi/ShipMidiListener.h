/*
 *  ShipMidiListener.h
 *  ModularShip
 *
 *  Created by Martial Geoffre on 10/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#pragma once
#include "ofMain.h"
#include "ofxMidi.h"
#include "ofxTubeManager.h"
#include "ofxSoundManager.h"
#include "superInterfacePanel.h"

class ShipMidiListener : public ofxMidiListener {
	
public:
	ShipMidiListener();
	~ShipMidiListener();
	void setup(ofxTubeManager * tubesManager,  ofxTubeManager * tubesManagerPreview,ofxSoundManager * soundManager, superInterfacePanel * panel);
	void newMidiMessage(ofxMidiEventArgs& eventArgs);
	
	
	int									oldVal;
	ofxTubeManager			*			tubesManager;
	ofxTubeManager			*			tubesManagerPreview;
	ofxSoundManager			*			soundManager;
	superInterfacePanel				*			panel;
	
	int									lastFrame;
	
};