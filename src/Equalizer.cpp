/*
 *  Equalizer.cpp
 *  ModularShip
 *
 *  Created by superscript_tower on 26/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Equalizer.h"
#include "mainSettings.h"

void Equalizer::init (vector<ofxTube*> * tubes, ofxSoundManager * sound) {
	
	bEnabled = false;
	intensity = 2;
	mode = 0;
	this->tubes = tubes;
	this->sound = sound;
	
	coords.x = mainSettings::getGridSize().x;
	coords.y =  mainSettings::getGridSize().y;
	
}

void Equalizer::update() {
	
	if(!bEnabled) return;
	
	
	//printf("mode : %d\n", mode);
	
	switch (mode) {
		case 0:
			doVerticalEqualizer();
			break;
			
		case 1:
			doHorizontalEqualizer();
			break;
			
		default:
			break;
	}
	
	

}

void Equalizer::doVerticalEqualizer () {
	
	int pCount = 0;
	for ( int z=0; z<2; z++ ) {
		
		for ( int i = 0; i < coords.x; i++) {
			
			//int index =  ( (coords.x - i ) * 128 / coords.x);
			
			int index = ( z < 1 ) ?(int)(( coords.x -1  - i ) * 128 / coords.x) : (int)(i * 128 / coords.x);
			
			float soundValue = ( z < 1 ) ? sound->leftAverage[index] : sound->rightAverage[index];
			
			for ( int j = 0; j < coords.y; j++) {
				
				if ( j % 3 == 0 ) {
					if ( i > coords.x - 2.0) continue;
				}
				
				
				
				tubes->at(pCount)->setActive(false);
				
				tubes->at(pCount)->nextTimeActive = 150.0;
				
				if ( tubes->at(pCount)->bVertical ) {
					
					tubes->at(pCount)->setActive(false);
					
				} else {
					
					
					
					if ( (int)(soundValue * coords.y) < coords.y -1 - j ) {
						tubes->at(pCount)->setActive(false);
					} else {
						tubes->at(pCount)->setActive(true);
					}
				}
				pCount++;
			}
			
		}
	}
	
	
	
}


void Equalizer::doHorizontalEqualizer () {
	
	int pCount = 0;
	for ( int z=0; z<2; z++ ) {
		
		for ( int i = 0; i < coords.x; i++) {
			
			
			
			for ( int j = 0; j < coords.y; j++) {
				
				if ( j % 3 == 0 ) {
					if ( i > coords.x - 2.0) continue;
				}
				
				int index = ( z < 1 ) ?(int)(( coords.y  - j ) * 128 / coords.y) : (int)(j * 128 / coords.y);
				
				//int index = (int)(i * 128 / coords.x);
				float soundValue = ( z < 1 ) ? sound->leftAverage[index] : sound->rightAverage[index];
				
				tubes->at(pCount)->setActive(false);
				
				tubes->at(pCount)->nextTimeActive = 150.0;
				
				if ( tubes->at(pCount)->bVertical ) {
					
					tubes->at(pCount)->setActive(false);
					
				} else {
					
					switch (z) {
						case 0:
							if ( (int)(soundValue * coords.x) < coords.x  - i ) {
								tubes->at(pCount)->setActive(false);
							} else {
								tubes->at(pCount)->setActive(true);
							}
							break;
							
						case 1:
							
							if ( (int)(soundValue * coords.x) > i ) {
								tubes->at(pCount)->setActive(true);
							} else {
								tubes->at(pCount)->setActive(false);
							}
							 
							
							break;
							
						default:
							break;
					}
					
					
					
				}
				
								
				pCount++;
			}
			
		}
	}
	
}
