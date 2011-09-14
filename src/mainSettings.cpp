/*
 *  mainSettings.cpp
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 26/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "mainSettings.h"

ofPoint mainSettings::getGridSize () {
	
	ofPoint size;
	size.x = 5;
	size.y = 19;
	return size;
	
}

ofPoint mainSettings::getGridPadding () {
	
	ofPoint padding;
	padding.x = 200.0;
	padding.y = 200.0;
	return padding;
	
}

ofPoint mainSettings::getPanelSize () {
	
	ofPoint size;
	size.x = 1920;
	size.y = 1080;
	return size;
	
}

int mainSettings::getNumOfTubePixels () {
	return 112;
}
