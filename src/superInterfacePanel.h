/*
 *  superInterfacePanel.h
 *  MODULAR_SHIP
 *
 *  Created by Martial on 12/09/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SPRINTPNL
#define SPRINTPNL

#include "ofMain.h"
#include "ofxSuperInterface.h"

#include "superInterfaceSimpleButton.h"
#include "superInterfaceFbo.h"
#include "superInterfaceHSlider.h"
#include "superInterfaceHIntSlider.h"
#include "ofxTubeManager.h"
#include "ofxSoundManager.h"
#include "fpsViewer.h"
#include "superInterfacePalettePicker.h"
#include "superInterfaceFFT.h"
#include "ofxXmlSettings.h"
#include "guiView.h"

class ofxTubeManager;

class superInterfacePanel {
	
public:
	
	void setup(ofxTubeManager * tubesManager, ofxSoundManager * sndManager, guiView * view2D);
	void update();
	void draw();
	
	void loadXML();
	void onClickHandler(string & label);
	
	
	ofxTubeManager * tubesManager;
	ofxSoundManager * sndManager;
	guiView			* view2D;
	
	fpsViewer		fps;
	
	ofxSuperInterface	superInterface;
	
	superInterfaceFFT	fft;
	superInterfaceFbo	fpsComp, view2DFbo;
	
	superInterfaceSimpleButton	opacity, size, reverse, color, tapTempo, sequencerEnabled;
	superInterfaceHSlider		speed, decay;
	superInterfaceHIntSlider	vertical, colorMode;
	//ofxSimpleGuiSliderInt * verticalSlider;
	
	ofColor				globalColor;
	vector<ofColor>		colors;
	vector<ofColor>		colorsTemp;
	bool				allColorsEnabled;
	
	float				colorTwoIntensity;
	bool				bcolorTwoSoundEnabled;
	
	vector<superInterfacePalettePicker*>	pickers;
	
private:
	
		
	ofxXmlSettings				xmlSettings;
	
	
	int					numOfPanels;
	
	
	
};

#endif