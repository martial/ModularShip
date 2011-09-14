/*
 *  ofxTubeMapping.cpp
 *  ModularShip
 *
 *  Created by Martial Geoffre on 23/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxTubeMapping.h"

void ofxTubeMapping::init (ofxTubeManager * tubeManager) {
	
	this->tubeManager = tubeManager;
	
	XML.loadFile("mapping.xml");
	
	XML.pushTag("assign", 0);
	int numOfAssigns = XML.getNumTags("item");
	
	//printf("Mapping, num of itmems %d\n", numOfAssigns);
	
	for ( int i=0; i < numOfAssigns; i++ ) {
		assignTubeId(i, XML.getValue("item", 0, i));
	}

	
}

void ofxTubeMapping::assignTubeId (int id, int mappingId) {
	
	for ( int i = 0; i<tubeManager->tubes.size(); i++ ) {
			
		ofxTube * tube = tubeManager->tubes[i];
		
		if ( tube->id == id ) {
			tube->mappingId = mappingId;
			
			return;
		}
		
	}
	
}

/*

void ofxTubeMapping::draw (float x, float y) {
	
	ofPushMatrix();
	ofTranslate(x+112, y+7, 0);
	
	float xPos = 0;
	float yPos = 0;
	
	int xCount = 0;
	
	float xPadding = 112;
	float yPadding = 1;
	
	int step = 2;
	int col = 14;
	int stepElapsed = 0;
	
	
	for ( int i = 0; i< 88; i++ ) {
		
	
		if ( i % col  == 0  ) {
			// doown
			yPos = 0;
			if ( i!= 0 ) stepElapsed++;
		}
		
		xPos = stepElapsed * (xPadding * step);
		
		xCount ++;
		if ( i % step  == 0 ) {
			// up
			yPos -= yPadding;
			xCount = 0;
			
		} else {
			xPos += xPadding * xCount;

		}
		
		
			
		ofSetColor(255, 255, 255);
		
		//ofPushMatrix();
	//	ofTranslate((int)xPos, yPos, 0);
		
		int tubeId = getTubeIndexForMappingId(i+1);
		tubeManager->tubes[tubeId]->drawForDisplay((int)xPos,yPos);
		
		//ofPopMatrix();
	}
	
	stepElapsed = 0;
	int yStepElapsed = 0;
	xCount = 0;
	xPos = 0;
	yPos = 0;
	
	int yCount = col-1;
	
	for ( int i = 0; i< 88; i++ ) {
		
		
		
		
		if ( i % col  == 0  ) {
			// doown
			yPos = 0;
			yCount = col-1;
			if ( i>= 84 ) yCount = 3;
			if ( i!= 0 ) yStepElapsed++;
			if ( i!= 0 ) stepElapsed++;
		} else {
			yCount --;
		}
		
		xPos = stepElapsed * (xPadding * step);
		
		xCount ++;
		if ( i % step  == 0 ) {
			// up
			yPos -= yPadding;
			xCount = 0;
			
			
		} else {
			xPos += xPadding * xCount;
			
		}
		
		
		int index = (176 - yCount -  ( yStepElapsed * (col)));
		
		ofSetColor(255, 255, 255);
		
		//ofPushMatrix();
	//	ofTranslate((int)xPos, yPos + 7, 0);
				
		int tubeId = getTubeIndexForMappingId(index-1);
		tubeManager->tubes[tubeId]->drawForDisplay((int)xPos,yPos+7);
		
	//	ofPopMatrix();
	}
	
	
	
	ofPopMatrix();
	
}

 */

void ofxTubeMapping::draw (float x, float y) {
	
	ofPushMatrix();
//	ofTranslate(x+112, y+7, 0);
	ofTranslate(x+112, y, 0);
	
	float xPos = 0;
	float yPos = 0;
	
	int xCount = 0;
	
	float xPadding = 112;
	float yPadding = 1;
	
	int step = 2;
	int col = 14;
	int stepElapsed = 0;
	
	int diffyPos = ( 7 * yPadding );
	
	ofColor color;
	color.set(255, 255,255);
	
	ofPushMatrix();
	glTranslated(0, ( 7* yPadding * 2 ) + ( 2 * yPadding ), 0);
	
	for ( int i = 0; i< 88; i++ ) {
		
		
		
		
		if ( i % col  == 0  ) {
			// doown
			
			if ( i!= 0 ) stepElapsed++;
			
			if ( stepElapsed == 3  && i != 0 ) {
				color.set(0, 255,255);
				stepElapsed = 0;
				diffyPos += ( i>= 84 )  ? yPadding * 2 : yPadding * 7;
				
			}
			yPos = 0 + diffyPos;
		}
		
		
		
		xPos = stepElapsed * (xPadding * step);
		
		xCount ++;
		if ( i % step  == 0 ) {
			// up
			yPos -= yPadding;
			
			xCount = 0;
			
		} else {
			xPos += xPadding * xCount;
			
		}
		
		
		
		
		
		
		//ofSetColor(color);
		
		//ofPushMatrix();
		//	ofTranslate((int)xPos, yPos, 0);
		
		int tubeId = getTubeIndexForMappingId(i+1);
		tubeManager->tubes[tubeId]->drawForDisplay((int)xPos,yPos);
		//int tubeId = getTubeIndexForMappingId(i+1);
		//ofDrawBitmapString(ofToString(i+1), xPos, yPos);
		
		
	//	ofRect(xPos, yPos, 5, 5);
		
		//ofPopMatrix();
	}
	
	ofPopMatrix();
	
	ofPushMatrix();
	//glTranslated(0, -( 7* yPadding * 2 ) + ( 2 * yPadding ), 0);
	
	stepElapsed = 0;
	int yStepElapsed = 0;
	xCount = 0;
	xPos = 0;
	yPos = 0;
	
	diffyPos = 0;
	
	int yCount = col-1;
	
	for ( int i = 0; i< 88; i++ ) {
		
		
		
		
		if ( i % col  == 0  ) {
			// doown
			
			yCount = col-1;
			if ( i>= 84 ) yCount = 3;
			if ( i!= 0 ) yStepElapsed++;
			if ( i!= 0 ) stepElapsed++;
			
			if ( stepElapsed == 3  && i != 0 ) {
				color.set(0, 255,255);
				stepElapsed = 0;
				diffyPos += ( i>= 84 )  ? yPadding * 2 : yPadding * 7;
				
			}
			yPos = 0+ diffyPos;
			
		} else {
			yCount --;
		}
		
		xPos = stepElapsed * (xPadding * step);
		
		xCount ++;
		if ( i % step  == 0 ) {
			// up
			yPos -= yPadding;
			xCount = 0;
			
			
		} else {
			xPos += xPadding * xCount;
			
		}
		
		
		int index = (176 - yCount -  ( yStepElapsed * (col)));
		
		ofSetColor(255, 255, 255);
		
		//ofPushMatrix();
		//	ofTranslate((int)xPos, yPos + 7, 0);
		
		int tubeId = getTubeIndexForMappingId(index);
		tubeManager->tubes[tubeId]->drawForDisplay((int)xPos,yPos+7);
		//ofDrawBitmapString(ofToString(index), xPos, yPos);
		//ofRect(xPos, yPos, 5, 5);

		//	ofPopMatrix();
	}
	
	ofPopMatrix();
	
	ofPopMatrix();
	
}

void ofxTubeMapping::debugDraw(float x, float y) {
	
	ofPushMatrix();
	//	ofTranslate(x+112, y+7, 0);
	ofTranslate(x+112, y, 0);
	
	float xPos = 0;
	float yPos = 0;
	
	int xCount = 0;
	
	float xPadding = 112;
	float yPadding = 10;
	
	int step = 2;
	int col = 14;
	int stepElapsed = 0;
	
	int diffyPos = ( 7 * yPadding );
	
	ofColor color;
	color.set(255, 255,255);
	
	ofPushMatrix();
	glTranslated(0, ( 7* yPadding * 2 ) + ( 2 * yPadding ), 0);
	
	for ( int i = 0; i< 88; i++ ) {
		
		
		
		
		if ( i % col  == 0  ) {
			// doown
			
			if ( i!= 0 ) stepElapsed++;
			
			if ( stepElapsed == 3  && i != 0 ) {
				color.set(0, 255,255);
				stepElapsed = 0;
				diffyPos += ( i>= 84 )  ? yPadding * 2 : yPadding * 7;
				
			}
			yPos = 0 + diffyPos;
		}
		
		
		
		xPos = stepElapsed * (xPadding * step);
		
		xCount ++;
		if ( i % step  == 0 ) {
			// up
			yPos -= yPadding;
			
			xCount = 0;
			
		} else {
			xPos += xPadding * xCount;
			
		}
		
		
		
		
		
		
		//ofSetColor(color);
		
		//ofPushMatrix();
		//	ofTranslate((int)xPos, yPos, 0);
		
		int tubeId = getTubeIndexForMappingId(i+1);
		//tubeManager->tubes[tubeId]->drawForDisplay((int)xPos,yPos);
		//int tubeId = getTubeIndexForMappingId(i+1);
		ofDrawBitmapString(ofToString(i+1), xPos, yPos);
		
		
		//	ofRect(xPos, yPos, 5, 5);
		
		//ofPopMatrix();
	}
	
	ofPopMatrix();
	
	ofPushMatrix();
	//glTranslated(0, -( 7* yPadding * 2 ) + ( 2 * yPadding ), 0);
	
	stepElapsed = 0;
	int yStepElapsed = 0;
	xCount = 0;
	xPos = 0;
	yPos = 0;
	
	diffyPos = 0;
	
	int yCount = col-1;
	
	for ( int i = 0; i< 88; i++ ) {
		
		
		
		
		if ( i % col  == 0  ) {
			// doown
			
			yCount = col-1;
			if ( i>= 84 ) yCount = 3;
			if ( i!= 0 ) yStepElapsed++;
			if ( i!= 0 ) stepElapsed++;
			
			if ( stepElapsed == 3  && i != 0 ) {
				color.set(0, 255,255);
				stepElapsed = 0;
				diffyPos += ( i>= 84 )  ? yPadding * 2 : yPadding * 7;
				
			}
			yPos = 0+ diffyPos;
			
		} else {
			yCount --;
		}
		
		xPos = stepElapsed * (xPadding * step);
		
		xCount ++;
		if ( i % step  == 0 ) {
			// up
			yPos -= yPadding;
			xCount = 0;
			
			
		} else {
			xPos += xPadding * xCount;
			
		}
		
		
		int index = (176 - yCount -  ( yStepElapsed * (col)));
		
		ofSetColor(255, 255, 255);
		
		//ofPushMatrix();
		//	ofTranslate((int)xPos, yPos + 7, 0);
		
		int tubeId = getTubeIndexForMappingId(index);
		//tubeManager->tubes[tubeId]->drawForDisplay((int)xPos,yPos+7);
		ofDrawBitmapString(ofToString(index), xPos, yPos);
		//ofRect(xPos, yPos, 5, 5);
		
		//	ofPopMatrix();
	}
	
	ofPopMatrix();
	
	ofPopMatrix();
	
	
}


int ofxTubeMapping::getTubeIndexForMappingId(int mappingId) {
	
	for ( int i = 0; i<tubeManager->tubes.size(); i++ ) {
		
		ofxTube * tube = tubeManager->tubes[i];
		if ( mappingId == tube->mappingId ) return i;
	}
	return 0;
}

