/*
 *  oscManager.cpp
 *  MODULAR_SHIP
 *
 *  Created by Martial on 12/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "oscManager.h"

void oscManager::setup(superInterfacePanel * panel) {
	
	this->panel = panel;
	receiver.setup(12345);
	//sender.setup("169.254.151.149", 33333);
	sender.setup("169.254.151.149", 33333);
	bHasFramedChanged = false;
}

void oscManager::update() {
	
	bHasFramedChanged = false;
	while( receiver.hasWaitingMessages() )
	{
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage( &m );
		
	
		
		string adress = m.getAddress();
		
		if ( adress == "color/color_0" ) {
			panel->allColorsEnabled = false;
			ofColor color;
			color.set(m.getArgAsFloat(0), m.getArgAsFloat(1), m.getArgAsFloat(2));
			panel->pickers[0]->setColor(color);
		}
		
		
		if ( adress == "color/color_1" ) {
			panel->allColorsEnabled = false;
			ofColor color;
			color.set(m.getArgAsFloat(0), m.getArgAsFloat(1), m.getArgAsFloat(2));
			panel->pickers[1]->setColor(color);
		}
		
		if ( adress == "color/color_2" ) {
			panel->allColorsEnabled = true;
			ofColor color;
			color.set(m.getArgAsFloat(0), m.getArgAsFloat(1), m.getArgAsFloat(2));
			panel->pickers[0]->setColor(color);
			panel->pickers[1]->setColor(color);
			panel->pickers[2]->setColor(color);
		}
		
		
		if ( adress == "freqRange/FFT" ) {
			
			panel->sndManager->setFilterRange(m.getArgAsInt32(0));
			panel->fft.setFilterRange(m.getArgAsInt32(0));
		}
		
		
		if ( adress == "seq/sequencer" && !bHasFramedChanged) {
			
			// how many pnts
			int numOfPnts = m.getNumArgs();
			vector<int> activePtns;
			for ( int i=1; i<numOfPnts; i++) {
				activePtns.push_back(m.getArgAsInt32(i));
			}
			
			panel->tubesManager->bSequencerMode =  m.getArgAsInt32(0);
			panel->tubesManager->setActivePoints(&activePtns);
			bHasFramedChanged = true;
			
		}
		
		
		
		
		
		ofLog(OF_LOG_NOTICE, m.getAddress());
	}
	
	
	
	ofxOscMessage fftMsg;
	fftMsg.setAddress("fft");
	for ( int i=0; i<panel->sndManager->range; i++ ) {
		int index = (int)(i * 128.0 / (float)panel->sndManager->range);
		fftMsg.addFloatArg(panel->sndManager->leftPreview[index]);
		
	}

	for ( int i=0; i<panel->sndManager->range; i++ ) {
		int index = (int)(i * 128.0 / (float)panel->sndManager->range);
		fftMsg.addFloatArg(panel->sndManager->rightPreview[index]);
		
	}
	sender.sendMessage(fftMsg);
	
	// colors values (constant)
	
	// sequencer values
	
	// frequence choosen value
	
	
	
	
	// must send freqs constantly
	
	
	
}