/*
 *  FlickeringDualBlinkAnim.h
 *  ModularShip
 *
 *  Created by superscript_tower on 27/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef FLICKRDUALANIM
#define FLICKRDUALANIM

#include "ofMain.h"
#include "AbstractTubeAnimation.h"
#include "ofxTween.h"
#include "ofxEasingQuint.h"

class FlickeringDualBlinkAnim : public  AbstractTubeAnimation {
    
public:
	
    FlickeringDualBlinkAnim();
    
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