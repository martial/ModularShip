/*
 *  Grid.cpp
 *  advanced3dExample
 *
 *  Created by Elliot Woods on 19/01/2011.
 *  Copyright 2011 Kimchi and Chips. All rights reserved.
 *
 */

#include "Grid.h"
#include "ofxTubeManager.h"

#include "mainSettings.h" 

Grid::Grid () {
	
	coords.x = mainSettings::getGridSize().x;
	coords.y =  mainSettings::getGridSize().y;
	
	padding.x =  mainSettings::getGridPadding().x;
	padding.y =  mainSettings::getGridPadding().y;
	
	showNumbers = false;
	showMappingNumbers = false;
	
	width = coords.x * padding.x * 2;
	height = coords.y * padding.y;
	
	centerPoint.x = ( coords.x * padding.x) - padding.x;
	centerPoint.y = ( coords.y * padding.y);
	
	rot.x = 0.0;
	rot.y = 0.0;
	rot.z = 0.0;
	
	rotToGo.x = 0.0;
	rotToGo.y = 0.0;
	rotToGo.z = 0.0;
	
	
	
		
	//ofRegisterMouseEvents(this);
	
}

void Grid::setSound(ofxSoundManager * sound, ofxTubeManager * tubesManager) {
		
	this->sound = sound;
	this->tubesManager = tubesManager;
}

void Grid::update () {
	
	
}

void Grid::updateMouse (ofRectangle rect) {
	
	
	
	ofVec2f mousePosScreen = ofVec3f(ofGetMouseX() - rect.width/2 - rect.x, rect.height/2 - (ofGetMouseY() - rect.y), 0);
	
	if( ofGetMousePressed(0)  && mousePosScreen.x > 0 ) {
				
		ofVec2f mouseDiffScreen = (mousePosScreen - mousePosScreenPrev);
		ofVec2f mouseVelScreen = mouseDiffScreen.lengthSquared();
		
		rotToGo.y -= mousePosScreen.x - mousePosScreenPrev.x;
		rotToGo.x += mousePosScreen.y - mousePosScreenPrev.y;	
				
	}
	
	rot.x = .75 * rot.x + (1 - .75) * rotToGo.x;
	rot.y = .75 * rot.y + (1 - .75) * rotToGo.y;


	
	mousePosScreenPrev = mousePosScreen;
	
}



void Grid::drawGrid (bool bFlat) {
	
	
	ofPushMatrix();
	
	glTranslatef(pos.x, pos.y, pos.z);
	glTranslatef(0, 20, 0);
	ofPoint pos;
	
	//fbo.begin();
	ofPushMatrix();
	
	
	glRotatef(rot.x, 1, 0, 0);
	glRotatef(rot.y, 0, 1, 0);
	
	if ( !bFlat) glTranslatef(-centerPoint.x, -centerPoint.y/2, 0);
	
	
	for ( int z=0; z< 2; z++ ) {
		
		ofPushMatrix();
		
		glTranslatef(z* ( centerPoint.x*2 ), 0, 0);
		if ( !bFlat)  glRotatef((z==0 ) ? 25 : -25, 0, 1, 0);
		glTranslatef(z* ( -centerPoint.x ), 0, 0);
		
	
		ofSetColor(15, 15, 15);
		ofSetLineWidth(1);
	
		for ( int i = 0; i < coords.x; i++) {		
			pos.x = (i * padding.x);
			ofLine(pos.x, 0, 0, pos.x, (coords.y * padding.y - padding.y) , 0  );
		}
	
		for ( int j = 0; j < coords.y; j++) {
			pos.y =  (j * padding.y);
			ofLine(0, pos.y,  0, coords.x * padding.x - padding.x, pos.y,  0);
		}
		ofPopMatrix();
	}
	
	ofPopMatrix();
	
	ofPopMatrix();	
	ofSetColor(255,255,255);
}

void Grid::drawTubes() {
	
	ofPushMatrix();
	
	glTranslatef(pos.x, pos.y, pos.z);
	
	ofPushMatrix();
	
	glRotatef(rot.x, 1, 0, 0);
	glRotatef(rot.y, 0, 1, 0);
	//glRotatef(ofGetMouseX(), 0, 0, 1);
	glTranslatef(-centerPoint.x, -centerPoint.y/2, 0);
	
	//glTranslatef(0, 20, 0);
	
	int count = 0;
	for ( int z=0; z< 2; z++ ) {
		
		ofPushMatrix();
		glTranslatef(z* ( centerPoint.x*2 ), 0, 0);
		glRotatef((z==0 ) ? 25 : -25, 0, 1, 0);
		
		glTranslatef(centerPoint.x/2 + (z* ( -centerPoint.x )), centerPoint.y/2, 0);
		if ( z == 0 ) {
			
			glRotatef(tubesManager->panelOneRotX, 1,0,0);
			glRotatef(tubesManager->panelOneRotY, 0,1,0);
			//glTranslatef(-centerPoint.x, 0, 0);
		}
		if ( z == 1 ) {
			glRotatef(tubesManager->panelTwoRotX, 1,0,0);
			glRotatef(tubesManager->panelTwoRotY, 0,1,0);
		}
		
		//glTranslatef(z* ( -centerPoint.x ), 0, 0);
		ofSetLineWidth(4);
		ofSetHexColor(0xffffff);
	
	
		ofEnableAlphaBlending();
	
	
		ofPoint pos;
			
		for ( int i = 0; i < coords.x; i++) {
		
			for ( int j = 0; j < coords.y ; j++) {
				ofSetColor(255, 255, 255);
				if ( j % 3 == 0 ) {
					ofSetColor(255, 0, 0);
					if ( i > coords.x - 2.0) continue;
				}
			
				pos.x = (i * padding.x) - centerPoint.x/2;
				pos.y = (j * padding.y) -centerPoint.y/2;
				
				
				ofPushMatrix();
				
				
				//int index = count;
				//tubesManager->tubes[count]->drawFor3DView(pos.x, pos.y);
				//glTranslatef(pos.x,  pos.y, 0);
				
				ofVec4f rot;
				rot.set(0,0,0,0);
				
				if ( j % 3 == 0 ) {
					rot.set(90,0,0,1);
					pos.x += padding.x/2 + mainSettings::getNumOfTubePixels()/2;
					pos.y += padding.y/2;
				}
				
				
				
				tubesManager->tubes[count]->drawFor3DView(pos.x, pos.y, rot);
				//ofRect(-2,  -12, 4, 24);
				//ofBox(0, 0, 0, 10);
								
				ofPopMatrix();
				
				
				if ( showNumbers  ) {
					ofPushStyle();
					ofSetColor(255, 255, 255);
					ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
					ofDrawBitmapString(ofToString((showMappingNumbers) ? tubesManager->tubes[count]->id : tubesManager->tubes[count]->mappingId, 0), pos.x, pos.y, 0);
					ofPopStyle();
				
				}
				 count++;
				 			
			}
		
		}
		
		ofPopMatrix();
		
	}

	
	ofDisableAlphaBlending();
	
	
	//tubesManager->updateVbo();
	//tubesManager->drawVbo();
	
	
	
	
	ofPopMatrix();
	
	
	ofPopMatrix();
	ofSetColor(255,255,255);
	
}

void Grid::drawDots () {
	
	ofPushMatrix();
	
	glTranslatef(pos.x, pos.y, pos.z);
	
	ofPushMatrix();
	
	//glRotatef(rot.x, 1, 0, 0);
	//glRotatef(rot.y, 0, 1, 0);
	//glTranslatef(-centerPoint.x, 0, -centerPoint.y);
	
	//glTranslatef(0, 20, 0);
	
	
	ofSetLineWidth(4);
	ofSetHexColor(0xffffff);
	
	
	ofEnableAlphaBlending();
	
	
	ofPoint pos;
	int pCount = 0;
	for ( int z=0; z< 2; z++ ) {
		
	glTranslatef(z* ( centerPoint.x  + 50), 0, 0);
	
	for ( int i = 0; i < coords.x; i++) {
		
		for ( int j = 0; j < coords.y; j++) {
			
			if ( j % 3 == 0 ) {
				if ( i > coords.x - 2.0) continue;
			}
			
			
			pos.x = (i * padding.x);
			pos.y = (j * padding.y);
			
			if ( j % 3 == 0 ) {
				pos.x += padding.x/2;
			//	pos.y += padding.y/2;
			}
			
			int index = (int)(i * coords.y + j);
			
			tubesManager->tubes[pCount]->drawFor2DView(pos.x, pos.y);
			pCount++;
			
		}
		
	}
	}
	ofDisableAlphaBlending();
	
	
	
	ofPopMatrix();
	
	
	ofPopMatrix();
	ofSetColor(255,255,255);	
	
}

void Grid::drawPlainGrid () {
	
	float scale = .2;
		
	ofPushMatrix();
	
	
	
	ofPushMatrix();
	
	//glRotatef(rot.x, 1, 0, 0);
	//glRotatef(rot.y, 0, 1, 0);
	//glTranslatef(-centerPoint.x, 0, -centerPoint.y);
	
	//glTranslatef(0, 20, 0);
	
	
	ofSetLineWidth(4);
	ofSetHexColor(0xffffff);
	
	
	ofEnableAlphaBlending();
	
	
	ofPoint pos, gridPos;
	int pCount = 0;
	for ( int z=0; z< 2; z++ ) {
		
		glTranslatef(z* ( centerPoint.x * scale  + 50), 0, 0);
		
		
		ofPushMatrix();
		
		ofSetColor(15, 15, 15);
		ofSetLineWidth(1);
		
		for ( int i = 0; i < coords.x; i++) {		
			gridPos.x = (i * padding.x * scale);
			ofLine(gridPos.x, 0, 0, gridPos.x, (coords.y * padding.y* scale - padding.y* scale) , 0  );
		}
		
		for ( int j = 0; j < coords.y; j++) {
			gridPos.y =  (j * padding.y* scale);
			ofLine(0, gridPos.y,  0, coords.x * padding.x* scale - padding.x* scale, gridPos.y,  0);
		}
		ofPopMatrix();	
		
		
		
		for ( int i = 0; i < coords.x; i++) {
			
			for ( int j = 0; j < coords.y; j++) {
				
				if ( j % 3 == 0 ) {
					if ( i > coords.x - 2.0) continue;
				}
				
				
				pos.x = (i * padding.x*scale);
				pos.y = (j * padding.y*scale);
				
				if ( j % 3 == 0 ) {
					pos.x += padding.x*scale/2;
					//	pos.y += padding.y/2;
				}
				
				int index = (int)(i * coords.y + j);
				
				ofSetColor(255, 0, 0);
				ofCircle(pos.x, pos.y, 4);
				
				//tubesManager->tubes[pCount]->drawFor2DView(pos.x, pos.y);
				pCount++;
				
			}
			
		}
	}
	ofDisableAlphaBlending();
	
	
	
	ofPopMatrix();
	
	
	ofPopMatrix();
	ofSetColor(255,255,255);	
	
	
}

void Grid::customDraw()
{
	
	
	
	//ofPushStyle();
		
	ofPoint centerPoint;
	centerPoint.x = ( coords.x * padding.x);
	centerPoint.y = ( coords.y * padding.y);
	ofPoint pos;
	
	ofPushMatrix();
	ofTranslate(-centerPoint.x, 0, -centerPoint.y);
	
	
	for ( int z=0; z< 2; z++ ) {; 
		
	ofPushMatrix();
	
	ofSetColor(125, 125, 125);
	ofSetLineWidth(1);
	
	for ( int i = 0; i < coords.x; i++) {		
		pos.x = (i * padding.x);
		ofLine(pos.x, 0, 0, pos.x, 0,   (coords.y * padding.y - padding.y) );
	}
	
	for ( int j = 0; j < coords.y; j++) {
		pos.y =  (j * padding.y);
		ofLine(0, 0,  pos.y, coords.x * padding.x - padding.x, 0,  pos.y);
	}
	
	
	ofSetLineWidth(4);
	ofSetHexColor(0xffffff);
	
	ofEnableAlphaBlending();
	
	
	for ( int i = 0; i < coords.x; i++) {
		
		for ( int j = 0; j < coords.y; j++) {
			
			pos.x = (i * padding.x);
			pos.y = (j * padding.y);
			
			int index = (int)(i * coords.y + j);
			
		//	tubesManager->tubes[index]->drawFor3DView(pos.x, pos.y);
			
			if ( showNumbers ) {
			ofPushStyle();
			ofSetColor(255, 255, 255);
			//ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
			ofDrawBitmapString(ofToString(i * coords.y + j, 0), pos.x, 0, pos.y);
			ofPopStyle();
			
			}
			
		}
		
	}
	
	ofDisableAlphaBlending();
	
	
	
	
	ofPopMatrix();	
	
	
	ofPopMatrix();
		
		ofPopMatrix();
	}
	
	
	//ofPopStyle();
	
	//fbo.end();
	
	/*
	ofPushMatrix();
	ofSetLineWidth(1);
	ofDrawAxis(100);
	ofPopMatrix();
	*/
	 
}