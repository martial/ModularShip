/*
 *  guiPanel.h
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 26/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GUIPNL
#define GUIPNL


#include "ofMain.h"
#include "fpsViewer.h"
#include "ofxXmlSettings.h"
#include "ofxPalettePicker.h"
#include "ofxSoundManager.h"
//#include "ofxTubeManager.h"


class guiPanel  {
	
	public:
	
	guiPanel();
	
	void	setup(ofxSoundManager * soundManager);
	void	parseXML();
	void	update();
	void	draw();
	
	void	onClickHandler(string & name);
	
	ofColor				globalColor;
	vector<ofColor>		colors;
	vector<ofColor>		colorsTemp;
	bool				allColorsEnabled;
	
	float				colorTwoIntensity;
	bool				bcolorTwoSoundEnabled;
	
	private:
	
	ofTrueTypeFont	nsFont;
	
	ofxSoundManager * sound;
	//ofxTubeManager * tubesManager;
	
	ofImage			logo;
	fpsViewer		fps;
	ofColor			color;
	
	
	ofxXmlSettings				xmlSettings;
	ofxPalettePicker		*	globalPicker;
	vector<ofxPalettePicker*>	pickers;
	
	int					numOfPanels;
	

};

#endif