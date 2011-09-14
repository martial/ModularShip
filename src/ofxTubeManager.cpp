/*
 *  ofxTubeManager.cpp
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 26/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxTubeManager.h"
#include "mainSettings.h"
#include "ofxSimpleGuiToo.h"
#include "superInterfacePanel.h"

ofxTubeManager::ofxTubeManager () {

}

void ofxTubeManager::setup (ofxSoundManager * sndManager, mainAnimData * animData, superInterfacePanel * panel) {
	
	this->sndManager = sndManager;
	this->animData = animData;
	this->panel = panel;
	//this->kinect = kinect;
	
	currentAnimation = 2;
	oldVerticalAnim = 0;
	
	
	sizeSoundEnabled = false;
	reverseFilled = false;
	bKinectMode = false;
	bSequencerMode = false;
	bFlickering = false;
	
	panelOneRotX = 0.0;
	panelTwoRotX = 0.0;
	
	panelOneRotY = 0.0;
	panelTwoRotY = 0.0;
	
	lastFrame = 0;
	
	player.setup();
	player.setAnimation(animData->animationsData[currentAnimation]);
	
	
	
	
	
	
	//gui.addToggle("Size + sound" , sizeSoundEnabled);
	//gui.addToggle("Reverse Filled" , reverseFilled);
	

	int pCount = 0;
	for ( int z=0; z<2; z++ ) {
		for ( int i = 0; i < mainSettings::getGridSize().x; i++) {		
			for ( int j = 0; j < mainSettings::getGridSize().y; j++) {				
				if ( j % 3 == 0 && i > mainSettings::getGridSize().x - 2.0 ) continue;	
				
				ofxTube * tube = new ofxTube();
				
				tube->setup(10, 8);
				tube->id = pCount;
				tube->bVertical = ( j % 3 == 0) ? true : false;
				tubes.push_back(tube);
				pCount++;
			}
		}
	}
	total = pCount;
	
	
	vAnimationManager.setup(&tubes, &player);
	soundManager.setup(sndManager, &tubes, &player);
	colorManager.setup(&tubes,panel);
	strob.init(&tubes);
	strob.bEnabled = false;
	
	rdmStrob.init(&tubes);
	rdmStrob.bEnabled = false;
	
	equalizer.init(&tubes, sndManager);
	equalizer.bEnabled = false;
	//displayFbo.setup(total, 36*2 + 4, GL_RGBA, 1);
	//gui.addFboContent("output", displayFbo);
}

void ofxTubeManager::roundRotations (int & rot) {
	
	if ( rot < 90 ) rot = 0;
	if ( rot >= 90 ) rot = 180;

}

void ofxTubeManager::update () {
	
	
	frameData * frame = player.update();
	if (!frame) return;
	
	setActivePoints(frame);
	vAnimationManager.update();
	colorManager.setColors();
	soundManager.update();
	
	for( int i = 0; i<total; i++ ) {
		tubes[i]->update();
	}	
	
	//lastFrame = ofGetFrameNum();
}

void ofxTubeManager::setActivePoints (frameData * frame) {
	
	if(!frame ) return;
	
	float playerTimeElapsed = player.timeElapsedSpeed;
	
	/*
	 effect
	 */
	
	if ( equalizer.bEnabled ) {
		equalizer.update();
		return;
	}
	
	if ( strob.bEnabled ) {
		strob.update();
		return;
	}
	
	if ( rdmStrob.bEnabled ) {
		rdmStrob.update();
		return;
	}
	
	
	
	for( int i = 0; i<total; i++ ) tubes[i]->setActive(false);
		
	int pointSize = frame->points.size();
	
	/*
	if ( bKinectMode ) {
		
		int pCount = 0;
		for ( int z=0; z<2; z++ ) {
			for ( int i = 0; i < mainSettings::getGridSize().x; i++) {		
				for ( int j = 0; j < mainSettings::getGridSize().y; j++) {				
					if ( j % 3 == 0 && i > mainSettings::getGridSize().x - 2.0 ) continue;	
					
					ofxTube * tube = tubes[pCount];
					
					if( tube->bActive ) break;
					
					for ( int k=0; k<kinect->points.size(); k ++ ) {
						
						// wrap to good proportions
						ofPoint pnt = kinect->points[k];
						pnt.x = ( 1 + pnt.x ) * 100.0f;
						pnt.z *= 100.0f;
						
						pnt.x *= (z+1);
						pnt.z *= (z+1);
						
						
						int _x = (int)(pnt.x * mainSettings::getGridSize().x / 200 );
						int _y = (int)(pnt.z * mainSettings::getGridSize().y / 200 );
						
						if ( _x == i+(mainSettings::getGridSize().x*z) && _y == j+(mainSettings::getGridSize().y*z) ) {						
							tube->setActive(true);
							break;
							
						}
					}
					pCount++;
				}
			}
		}
		return;
	}
	*/
	
	if ( bSequencerMode ) {
		
		int actCount = 0;
		
		for ( int i = 0; i < total; i++) {
			
			ofxTube * tube = tubes[i];
						
			for ( int j=0; j<sequencerActivePnts.size(); j++ ) {
				
				if ( sequencerActivePnts[j] == i ) {
					
					tubes[i]->nextTimeInactive = 0.0 ;
					tubes[i]->nextTimeActive = 1000.0 ;
					tube->setActive(true);
					actCount++;
					
				}
			}
		}	
		
		
		//bSequencerMode = false;
		return;
	}
	
	
	if ( animData->animationsData[currentAnimation]->isDualMode == 0 ) {
		
		
		
		for ( int i = 0; i < total; i++) {
			vector<int>::iterator it  = find(frame->points.begin(), frame->points.end(), i);
			if ( it != frame->points.end()) {
								
				int nextInactivePoint = player.currentAnimationData->getNextActivePointAt(player.currentFrame, i, (player.sens == 1 ) ? true : false, true);
				int nextActivePoint = player.currentAnimationData->getNextActivePointAt(player.currentFrame, i, (player.sens == 1 ) ? true : false, false);
				
				float timeInactiveElapsed = nextInactivePoint * playerTimeElapsed;
				
				float timeActiveElapsed = nextActivePoint * playerTimeElapsed;
				
				tubes[i]->nextTimeInactive = timeInactiveElapsed ;

				tubes[i]->nextTimeActive = timeActiveElapsed ;

				tubes[i]->setActive(true);
			} 
		}
		return;
	}
	
	
		
	if ( animData->animationsData[currentAnimation]->isDualMode == 1 ) {
		
		
		
		for ( int i = 0; i < pointSize; i++) {
			for( int j = 0; j<total*.5; j++ ) {
				
				
				vector<int>::iterator it  = find(frame->points.begin(), frame->points.end(), tubes[j]->id);
				
				if ( it != frame->points.end()) {
					
					int nextInactivePoint = player.currentAnimationData->getNextActivePointAt(player.currentFrame, i, (player.sens == 1 ) ? true : false, true);
					int nextActivePoint = player.currentAnimationData->getNextActivePointAt(player.currentFrame, i, (player.sens == 1 ) ? true : false, false);
					
					float timeInactiveElapsed = nextInactivePoint * playerTimeElapsed;

					float timeActiveElapsed = nextActivePoint * playerTimeElapsed;
					
					tubes[tubes[j]->id]->nextTimeInactive = timeInactiveElapsed ;
					tubes[88 + tubes[j]->id ]->nextTimeInactive = timeInactiveElapsed ;
					
					tubes[tubes[j]->id]->nextTimeActive = timeActiveElapsed;
					tubes[88 + tubes[j]->id ]->nextTimeActive = timeActiveElapsed;
					
					
					//tubes[i]->nextTimeActive = ( nextTimeActive < 100.0 ) nextTimeActive : 100.0;
					
					/*
					tubes[tubes[j]->id]->nextTimeActive = ( nextTimeActive < 200.0 ) ? nextTimeActive : 200.0;
					tubes[88 + tubes[j]->id ]->nextTimeActive = ( nextTimeActive < 200.0 ) ? nextTimeActive : 200.0;
					
					 */
					 
					tubes[tubes[j]->id ]->setActive(true);	
					tubes[88 + tubes[j]->id ]->setActive(true);	
					
				} 
				
			}
		}
	}
	
}

void ofxTubeManager::setActivePoints (vector<int> * activePoints) {
	
	sequencerActivePnts.clear();
	for ( int i=0; i<activePoints->size();i++) {
		sequencerActivePnts.push_back(activePoints->at(i));
		ofLog(OF_LOG_NOTICE, "set %d",activePoints->at(i));
	}
	
	
}


void ofxTubeManager::setAnimation (int id) {
	
	//printf("Set animation \n");
	
	currentAnimation = id;
	if ( currentAnimation > animData->animationsData.size() -1 ) currentAnimation = 0;
	if ( currentAnimation < 0 ) currentAnimation = animData->animationsData.size() -1;
	
	
	player.setAnimation(animData->animationsData[currentAnimation]);
	
	if (lastFrame != ofGetFrameNum()) {
	resetTubesState();
	lastFrame = ofGetFrameNum();
	}
	
	vAnimationManager.reset();
	
	printf("set animation \n");
	
}

void ofxTubeManager::increaseAnimation(bool bIncreasing) {
	
	//printf("increase anim\n");
	
	if ( bIncreasing ) {
		pushAnimation();
		
	} else {
		popAnimation();
	}
	
	
}

void ofxTubeManager::pushAnimation () {
	
	//printf("push anim\n");
		
	
	
	
	
	
	
	currentAnimation++;
	if ( currentAnimation > animData->animationsData.size() -1 ) currentAnimation = 0;
	player.setAnimation(animData->animationsData[currentAnimation]);
	//resetTubesState();
}

void ofxTubeManager::popAnimation () {
	
	//printf("pop anim\n");
	
	currentAnimation--;
	if ( currentAnimation < 0 ) currentAnimation = animData->animationsData.size() -1;
	player.setAnimation(animData->animationsData[currentAnimation]);
	//resetTubesState();
}

void ofxTubeManager:: enableFlickering(bool bFlickering) {
	
	if ( this->bFlickering == bFlickering ) return;
	
	this->bFlickering = bFlickering;
	
	
	for( int i = 0; i<total; i++ ) {
		tubes[i]->bFlickering = bFlickering;
	}
	forceSimpleVertical(bFlickering);

}

void ofxTubeManager::setFlickeringRange(int val) {
	
	
	
	//flickeringRange = val;
	if ( val <= 4 ) {
		val = 4;
	} else {
		
	}
	
	
	for( int i = 0; i<total; i++ ) {
		tubes[i]->flickeringRange = val;
	}
}


void ofxTubeManager::resetTubesState () {
	
	for( int i = 0; i<total; i++ ) {
		tubes[i]->reset();
	}
	
}

void ofxTubeManager::forceSimpleVertical (bool bEnabled) {
	
	//resetTubesState();
	if ( bEnabled ) {
		oldVerticalAnim = vAnimationManager.mode;
		vAnimationManager.setCurrentAnimationById(0);
		//resetTubesState();
	} else {
		vAnimationManager.setCurrentAnimationById(oldVerticalAnim);
		//resetTubesState();
	}
	
	
}

ofFbo * ofxTubeManager::drawForDisplay (int x, int y) {
	
	return &displayFbo;
}

void ofxTubeManager::setStageOpacity(float pct) {
		
	for( int i = 0; i<total; i++ ) {
		tubes[i]->stageAlphaPct = pct;
	}
	
}



