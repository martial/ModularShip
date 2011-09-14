/*
 *  ofxColorTubeManager.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 04/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxColorTubeManager.h"
#include "mainSettings.h"
#include "ofxSimpleGuiToo.h"
#include "superInterfacePanel.h"


void ofxColorTubeManager::setup(vector<ofxTube*> * tubes, superInterfacePanel * panel) {
	
	this->tubes = tubes;
	this->panel = panel;
	
	total = tubes->size();
	numOfTubePixels = mainSettings::getNumOfTubePixels();
	mode = 1;
	
	coords.x = mainSettings::getGridSize().x;
	coords.y =  mainSettings::getGridSize().y;
	
	
	
}

void ofxColorTubeManager::setMode(int index) {
	mode = index;
}

void ofxColorTubeManager::setColors () {
	
	
	
	switch (mode) {
		case 0:
			doNormalGradient();
			break;
		
		case 1:
			doHorizontalGradient();
			break;
		case 2:
			doVerticalGradient();
			break;
		
		case 3:
			doSymetricVerticalGradient();
			break;
		
		case 4:
			doSymetricHorizontalGradient();
			break;
			
		case 5:
			doTestColor();
			break;
			
		default:
			doNormalGradient();
			break;
	}
	
	
	
}



void ofxColorTubeManager::doNormalGradient () {
	
	vector<ofColor> * newColors = colorUtils.getGradient(&panel->colorsTemp, total);
	
	for( int i = 0; i<total; i++ ) {
		
		ofColor current = newColors->at(i);
		for( int j = 0; j<numOfTubePixels; j++ ) {
			tubes->at(i)->pixels[j]->color.r = current.r;
			tubes->at(i)->pixels[j]->color.g = current.g;
			tubes->at(i)->pixels[j]->color.b = current.b;
		}
		
	}
}


void ofxColorTubeManager::doHorizontalGradient () {
	
	vector<ofColor> * newColors = colorUtils.getGradient(&panel->colorsTemp, total);
	
	int pCount = 0;
	for ( int z=0; z<2; z++ ) {
	
	for ( int i = 0; i < coords.x; i++) {
		
		ofColor current = newColors->at(pCount);
		
		for ( int j = 0; j < coords.y; j++) {
			
			if ( j % 3 == 0 ) {
				if ( i > coords.x - 2.0) continue;
			}
			
			//int index = j * coords.y + i;
			vector<ofColor> * newColorsTube = colorUtilsTube.getGradient(&panel->colorsTemp, numOfTubePixels);
			
			for( int k = 0; k<numOfTubePixels; k++ ) {
			
			ofColor currentTubeColor = newColorsTube->at(k);

		//	if ( pCount > 175 ) return; 
			tubes->at(pCount)->pixels[k]->color.r = currentTubeColor.r;
			tubes->at(pCount)->pixels[k]->color.g = currentTubeColor.g;
			tubes->at(pCount)->pixels[k]->color.b = currentTubeColor.b;
			
			}
			
			pCount++;
		}
		
		}
	}
	
}


void ofxColorTubeManager::doVerticalGradient () {
	
	vector<ofColor> * newColors = colorUtils.getGradient(&panel->colorsTemp, coords.y);
	
	int pCount = 0;
	for ( int z=0; z<2; z++ ) {
		
		for ( int i = 0; i < coords.x; i++) {
			
			
			
			for ( int j = 0; j < coords.y; j++) {
				
				if ( j % 3 == 0 ) {
					if ( i > coords.x - 2.0) continue;
				}
				
				ofColor current = newColors->at(j);
				
				//int index = j * coords.y + i;
				//vector<ofColor> * newColorsTube = colorUtilsTube.getGradient(&panel->colors, numOfTubePixels);
				
				for( int k = 0; k<numOfTubePixels; k++ ) {
				
					tubes->at(pCount)->pixels[k]->color.r = current.r;
					tubes->at(pCount)->pixels[k]->color.g = current.g;
					tubes->at(pCount)->pixels[k]->color.b = current.b;
					
				}
				
				pCount++;
			}
			
		}
	}
	
	
}


void ofxColorTubeManager::doSymetricVerticalGradient () {
	
	// just adding one should do the trick ;)
	
	
	vector<ofColor> * newColors = colorUtils.getGradient(&panel->colorsTemp, (int)(coords.y*.5));
	
	int pCount = 0;
	for ( int z=0; z<2; z++ ) {
		
		for ( int i = 0; i < coords.x; i++) {
			
			
			
			for ( int j = 0; j < coords.y; j++) {
				
				if ( j % 3 == 0 ) {
					if ( i > coords.x - 2.0) continue;
				}
				
				
				ofColor current = ( j < coords.y *.5 ) ? newColors->at(j): newColors->at( (int)(coords.y)-j);
				
				
				for( int k = 0; k<numOfTubePixels; k++ ) {
					
					tubes->at(pCount)->pixels[k]->color.r = current.r;
					tubes->at(pCount)->pixels[k]->color.g = current.g;
					tubes->at(pCount)->pixels[k]->color.b = current.b;
					
				}
				
				pCount++;
			}
			
		}
	}
	
	
}

void ofxColorTubeManager::doSymetricHorizontalGradient () {
	
	// just adding one should do the trick ;)
	
	
	vector<ofColor> * newColors = colorUtils.getGradient(&panel->colorsTemp, (int)(coords.x));
	
	int pCount = 0;
	for ( int z=0; z<2; z++ ) {
		
		for ( int i = 0; i < coords.x; i++) {
			
			ofColor current =  ( z < 1 ) ? newColors->at(i) :  newColors->at(coords.x -1 - i);
			
			for ( int j = 0; j < coords.y; j++) {
				
				if ( j % 3 == 0 ) {
					if ( i > coords.x - 2.0) continue;
				}
								
				for( int k = 0; k<numOfTubePixels; k++ ) {
					
					tubes->at(pCount)->pixels[k]->color.r = current.r;
					tubes->at(pCount)->pixels[k]->color.g = current.g;
					tubes->at(pCount)->pixels[k]->color.b = current.b;
					
				}
				
				pCount++;
			}
			
		}
	}
	
	
}

void ofxColorTubeManager::doTestColor () {
	
	int pCount = 0;
	for ( int z=0; z<2; z++ ) {
		
		for ( int i = 0; i < coords.x; i++) {
			
			//ofColor current =  ( z < 1 ) ? newColors->at(i) :  newColors->at(coords.x -1 - i);
			
			for ( int j = 0; j < coords.y; j++) {
				
				if ( j % 3 == 0 ) {
					if ( i > coords.x - 2.0) continue;
				}
				
				ofColor colorToGo;
				
				if ( j % 3 == 0 ) {
					( i %2 == 0 )  ? colorToGo.set(255, j*255/coords.y,i*255/coords.x) : colorToGo.set(0, j*255/coords.y,i*255/coords.x);
				
				} else {
					colorToGo.set(255,j*255/coords.y,i*255/coords.x);
				}
				
				tubes->at(pCount)->setActive(true);
				
				for( int k = 0; k<numOfTubePixels; k++ ) {
					
					tubes->at(pCount)->pixels[k]->color.r = colorToGo.r;
					tubes->at(pCount)->pixels[k]->color.g = colorToGo.g;
					tubes->at(pCount)->pixels[k]->color.b = colorToGo.b;
					
				}
				
				pCount++;
			}
			
		}
	}
	
	
	
}



