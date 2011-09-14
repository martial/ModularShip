/*
 *  ofxSoundTubeManager.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 06/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxSoundTubeManager.h"
#include "ofxSimpleGuiToo.h"
#include "mainSettings.h"

ofxSoundTubeManager::ofxSoundTubeManager () {
	
}

void ofxSoundTubeManager::setup(ofxSoundManager * soundManager, vector<ofxTube*> * tubes, ofxAnimPlayer * animPlayer) {
	
	this->soundManager = soundManager;
	this->tubes = tubes;
	this->animPlayer = animPlayer;
	
	total = tubes->size();
	
	mode = 1;
	
	
	coords.x = mainSettings::getGridSize().x;
	coords.y =  mainSettings::getGridSize().y;
	
	sizeSoundEnabled = false;
	opacitySoundEnabled = false;
	speedEnabled = false;
	
}


void ofxSoundTubeManager::update () {
	
	animPlayer->bSpeedByframe = speedEnabled;
	if ( speedEnabled ) {
		animPlayer->framePct = soundManager->leftAverage[68];
	
	}
	for( int i = 0; i<total; i++ ) {
		ofxTube * tube = tubes->at(i);
		if ( !opacitySoundEnabled )tube->setMainAlphaPct(1.0);
		if ( !sizeSoundEnabled ) tube->globalSizePct = 1.0;
	}
	
	switch ( mode ) {
				
		case 0:
			doNormalGrid();
			break;
			
		case 1:
			doVerticalStereo();
			break;
			
		case 2:
			doHorizontalStereo();
			break;
			
			
	}
	
	//doNormalGrid();
	
}

void ofxSoundTubeManager::doNormalGrid () {
	
	
	for( int i = 0; i<total; i++ ) {
		
		int step = floor(i * 128 / total);
		ofxTube * tube = tubes->at(i);
		if ( opacitySoundEnabled ) tube->setMainAlphaPct(soundManager->left[step]);
		if ( sizeSoundEnabled ) tube->globalSizePct = soundManager->left[step];
	}
}


void ofxSoundTubeManager::doVerticalStereo(){
	
	int pCount = 0;
	for ( int i = 0; i < coords.x; i++) {
			for ( int j = 0; j < coords.y ; j++) {
					
				if ( j % 3 == 0 ) {
					if ( i > coords.x - 2.0) continue;
				}
			
			int step = floor(pCount  * 128 / (88));
				
			
			ofxTube * tubeLeft = tubes->at(pCount);
			if ( opacitySoundEnabled )tubeLeft->setMainAlphaPct(soundManager->left[127-step]);	
			if ( sizeSoundEnabled )tubeLeft->globalSizePct = soundManager->left[127-step];
				
			int index = 88 + pCount;
			if ( index > 175 ) return;
					
			pCount++;
					
			ofxTube * tubeRight = tubes->at(index);
			if ( opacitySoundEnabled )tubeRight->setMainAlphaPct( soundManager->right[step] );	
			if ( sizeSoundEnabled )tubeRight->globalSizePct = soundManager->right[step];
		}
	}
}


void ofxSoundTubeManager::doHorizontalStereo(){
	
	for ( int i = 0; i < coords.x; i++) {
		
		int step = ( i< coords.x / 2 ) ?  floor(i * 2 * 128 / (coords.x-1)) : floor( (i-coords.x / 2 )  *  2 * 128 / (coords.x-1));
		float val = ( i< coords.x / 2 ) ? soundManager->left[127-step] : soundManager->right[step] ;
				
		for ( int j = 0; j < coords.y ; j++) {
			
			ofxTube * tube = tubes->at(i * coords.y + j);
			if ( opacitySoundEnabled ) tube->setMainAlphaPct(val);	
			if ( sizeSoundEnabled ) tube->globalSizePct = val;	
		}
	}
}

void ofxSoundTubeManager::doVerticalCenteredStereo(){
}
void ofxSoundTubeManager::doHorizontalCenteredStereo(){
}


