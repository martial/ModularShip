/*
 *  Stroboscope.cpp
 *  ModularShip
 *
 *  Created by Martial Geoffre on 19/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Stroboscope.h"

void Stroboscope::init (vector<ofxTube*> * tubes) {

	bEnabled = false;
	intensity = 2;
	this->tubes = tubes;
	
}

void Stroboscope::update() {
	
	
	
	if(!bEnabled) return;
	
	
	
	bool active =  ( ofGetFrameNum() % intensity == 0 ) ? true : false;

	for ( int i= 0; i<tubes->size(); i++ ) {
		tubes->at(i)->setActive(active);
	}
	
	

}