/*
 *  Grid.h
 *  advanced3dExample
 *
 *  Created by Elliot Woods on 19/01/2011.
 *  Copyright 2011 Kimchi and Chips. All rights reserved.
 *
 */

// Grid is a custom 3D
// object that we've
// created in this
// example.
//
// We inherit from ofNode

#ifndef GRD
#define GRD

#include "ofMain.h"
#include "ofxSoundManager.h"


class ofxTubeManager;

class Grid 
{
public:
	Grid();
	void		setSound(ofxSoundManager * sound, ofxTubeManager * tubesManager);
	
	void		update();
	void		updateMouse (ofRectangle rect);
	void		updateVbo();
	
	void		drawGrid(bool bFlat = false );
	void		drawDots();
	void		drawTubes();
	void		customDraw();
	void		drawPlainGrid();
	
	ofVec3f		pos;
	ofPoint		coords;
	ofPoint		padding;
	float		width, height;
	
	bool						showNumbers;
	bool						showMappingNumbers;
	
	//ofFbo						fbo;
	
private:
	ofxSoundManager		*		sound;
	ofxTubeManager		*		tubesManager;
	
	ofPoint						centerPoint;
	
	ofVec3f						rotToGo, rot;
	ofVec2f						mousePosScreenPrev;
	int							lastMouseY;
	
	
};

#endif