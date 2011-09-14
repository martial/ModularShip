/*
 *  DualBlinAnim.h
 *  ModularShip
 *
 *  Created by superscript_tower on 25/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef DUALBLIKANIM
#define DUALBLIKANIM

#include "ofMain.h"
#include "AbstractTubeAnimation.h"
#include "ofxTween.h"
#include "ofxEasingQuint.h"

class DualBlinAnim : public  AbstractTubeAnimation {
    
public:
	
    DualBlinAnim();
    
    void init(string name, vector<ofxTube*> * tubes);
    void launch(vector<ofxTube*> * tubes);
	
	
    void onAnimationStart(ofxTubeEvent * args);
    void onAnimationEnd(ofxTubeEvent * args);
	
	void onAnimationLoopEvent(int & a);
	void onTubeUpdateEvent(ofxTubeEvent & args);
    
    void update();
	
	void quit();
    
    void setEstimatedAnimationTime(float time);
	
	
	private :
	
	int						limit;
	int						pixelIndex, numOfTubePixels;
	int						middle;
	ofxTween				pixelTween;
	ofxEasingQuint			easingquint;
    
    
};

#endif