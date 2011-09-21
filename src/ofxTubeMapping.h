/*
 *  ofxTubeMapping.h
 *  ModularShip
 *
 *  Created by Martial Geoffre on 23/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TBMAPPING
#define TMBMAPPING

#include "ofMain.h"
#include "ofxTubeManager.h"
#include "ofxXmlSettings.h"
#include "ofxTube.h"

class ofxTubeMapping {

public:
	
	void init(ofxTubeManager * tubeManager);
	void assignTubeId (int id, int mappingId);
	int getTubeIndexForMappingId(int mappingId);
	void draw(float x, float y);
	void drawName(float x, float y);
	void debugDrawName (float x, float y);
	void debugDraw(float x, float y);
	
	ofxTubeManager * tubeManager;
	
	ofxXmlSettings	XML;
	
	vector<int>		assigns;
	
};


#endif