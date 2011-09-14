/*
 *  oscManager.h
 *  MODULAR_SHIP
 *
 *  Created by Martial on 12/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef OSCMNG
#define OSCMNG

#include "ofMain.h"
#include "ofxOscReceiver.h"
#include "ofxOscSender.h"
#include "superInterfacePanel.h"
class oscManager {
		
public:
	
	void setup(superInterfacePanel * panel);
	void update();
	
	
	
	
	ofxOscReceiver	receiver;
	ofxOscSender	sender;
	
	superInterfacePanel * panel;
	bool				bHasFramedChanged;
};


#endif