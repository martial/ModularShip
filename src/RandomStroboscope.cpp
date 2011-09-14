/*
 *  RandomStroboscope.cpp
 *  ModularShip
 *
 *  Created by Martial Geoffre on 24/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "RandomStroboscope.h"

void RandomStroboscope::init (vector<ofxTube*> * tubes) {
	
	bEnabled = false;
	intensity = 2;
	this->tubes = tubes;
	
}

void RandomStroboscope::update() {
	
	if(!bEnabled) return;
	
	bool active =  ( ofGetFrameNum() % 2 == 0 ) ? true : false;
	
	for ( int i= 0; i<tubes->size(); i++ ) {
		float rdm = ofRandom(10);
		
		tubes->at(i)->setActive(false);
		
		if ( rdm >= intensity  ) {
		tubes->at(i)->setActive(true);
		} else {
		tubes->at(i)->setActive(false);
		}
	}
	
	
	
}