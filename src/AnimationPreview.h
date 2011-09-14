/*
 *  AnimationPreview.h
 *  ModularShip
 *
 *  Created by superscript_tower on 26/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ANIMVERTPREVW
#define ANIMVERTPREVW

#include "ofMain.h"
#include "AbstractTubeAnimation.h"
#include "ofxTube.h"
#include "ofxTubeEvent.h"
#include "ofxAnimPlayer.h"
#include "mainSettings.h"
#include "ofxFBOTexture.h"

class AnimationPreview {
    
public:
    
   // AnimationPreview();
	
    void setup(ofxTube * tube);
    void update();
	void draw(float x, float y);
	
	ofxTube * tube;
	ofxFBOTexture	* fbo;
    

};

#endif