/*
 *  guiPanel.cpp
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 26/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "guiPanel.h"
#include "ofxSimpleGuiToo.h"



guiPanel::guiPanel () {

}

void guiPanel::setup (ofxSoundManager * soundManager) {
	
	this->sound = soundManager;
	
	
	logo.loadImage("logo.png");
	fps.setup(256, 40, 60);
	
	xmlSettings.loadFile("colors.xml");	
	gui.addFboContent("fps", fps.fbo);

	gui.show();
	
	
	globalColor.set(255,255,255);
	colorTwoIntensity = 1.0;
	
	bcolorTwoSoundEnabled = false;
	
}

void guiPanel::parseXML() {
	
	xmlSettings.pushTag("colors");
	
	numOfPanels = xmlSettings.getNumTags("panel");
	colors.reserve(numOfPanels);
	colorsTemp.reserve(numOfPanels);
	
	for ( int i = 0; i < numOfPanels; i++ ) {
		
		xmlSettings.pushTag("panel", i);
		
		ofColor color;
		color.set(255, 255, 255);
		colors.push_back(color);
		colorsTemp.push_back(color);
		
		string name = ( i != numOfPanels-1 ) ? "Gradient " + ofToString(i) : "All Colors";
		ofColor * targetColor = ( i != numOfPanels-1 ) ? &colors[i] : &globalColor;
		
		ofxPalettePicker * palette = &gui.addPalettePicker(name, targetColor);
		if ( i==0 ) palette->setNewColumn(true);
		ofAddListener(palette->onClickEvent, this, &guiPanel::onClickHandler);
		pickers.push_back(palette);
		
		int numOfColors = xmlSettings.getNumTags("color");
		
		for ( int j=0; j<numOfColors;j++) {
			
			ofColor colorPalette;
			int r = xmlSettings.getAttribute("color", "r", 0, j);
			int g = xmlSettings.getAttribute("color", "g", 0, j);
			int b = xmlSettings.getAttribute("color", "b", 0, j);
			colorPalette.set(r, g, b);
			palette->addColor(colorPalette);
			
		}
		xmlSettings.popTag();
	}
	
}

void guiPanel::onClickHandler(string & name) {
	
	if ( name=="All Colors" ) {
		allColorsEnabled = true;
	} else {
		allColorsEnabled = false;
	}
	
}

void guiPanel::update () {
	
	//ofColor secondColor = colors[1];
	
	// copy second colorcolor
	//colorsTemp[1].r = colors[1].r;
	//colorsTemp[1].g = colors[1].g;
	//colorsTemp[1].b = colors[1].b;
	//colorsTemp[1].a = colors[1].a;
	
	// calculate diff
	
	colorTwoIntensity = (bcolorTwoSoundEnabled) ? sound->left[64] : 1.0;
	
	colorsTemp[0] = colors[0];
	colorsTemp[2] = colors[2];
	
	colorsTemp[1].r = colors[0].r + ((colors[1].r - colors[0].r) * colorTwoIntensity);
	colorsTemp[1].g = colors[0].g + ((colors[1].g - colors[0].g) * colorTwoIntensity);
	colorsTemp[1].b = colors[0].b + ((colors[1].b - colors[0].b) * colorTwoIntensity);
	
	/*,*/
		
	 /*-*/
		
		if ( allColorsEnabled ) {
			
			for ( int i=0; i<pickers.size()-1;i++) {
				//colors[i] = globalColor;
				ofColor ahou;
				ahou.set(globalColor.r, globalColor.g, globalColor.b);
				pickers[i]->setColor(ahou);
			}
		}
		
	
	//fps.update();
}

void guiPanel::draw () {
	
	//nsFont.drawString("ahouuuu", 0, 0);
	
	ofEnableAlphaBlending();
	ofSetHexColor(0xffffff);
	logo.draw(0, 30);
	ofDisableAlphaBlending();
	fps.draw(0, 0, 256, 40, true);
	gui.draw();
}