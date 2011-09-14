/*
 *  guiView.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 04/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "guiView.h"
#include "ofxTubeManager.h"

void guiView::setup(ofxSoundManager * sound, ofxTubeManager * tubesManager) {
	
	
	this->sound = sound;
	this->tubesManager = tubesManager;
	
	
	nodeGrid.setSound(sound, tubesManager);
	
		
    
    setSize( nodeGrid.width,  nodeGrid.height);	
	fbo.allocate(nodeGrid.width*2 * .2, nodeGrid.height*.2, GL_RGBA, 1);		
	
	
	//gui.addSlider("Blur amnt", blurAmount, 0, 10);
	
	
}

void guiView::update() {
	
	//printf("update \n");
	
	nodeGrid.update();
	
	string name = tubesManager->animData->animationsData[tubesManager->currentAnimation]->name;
	string userName = tubesManager->animData->animationsData[tubesManager->currentAnimation]->userName;
	string id = ofToString(tubesManager->animData->animationsData[tubesManager->currentAnimation]->id);
	

	
	//fboContentGui->name = id + " | "+ userName + " | " + name;
	
}

void guiView::draw(int x, int y) {
	
	//ofSetColor(0, 0, 0);
	
	
	//fbo.clear();
	fbo.begin();
	ofClear(0.0, 0.0, 0.0, 1.0);
	///cam.begin();
	
	//nodeGrid.drawGrid(true);
	//cam.end();
	
	ofPushMatrix();
	glScalef(.2, .2, .2);
	glColor3f(1, 1, 1);
	glTranslated(100, 100, 0);
	//glRotated(180, 1, 1, 0);
	
	ofEnableAlphaBlending();
	nodeGrid.drawDots();
	ofDisableAlphaBlending();
	ofSetColor(255, 255, 255);
	ofPopMatrix();
	fbo.end();
	
   
	
}

void guiView::setSize(int w, int h) {
    width = w;
    height = h;
    
}

void guiView::onWindowsResized( int w, int h) {
    
    setSize( ofGetWidth() - 320,  ofGetHeight() - 135);
    fbo.allocate(width, height, GL_RGBA, 1);
    
}
