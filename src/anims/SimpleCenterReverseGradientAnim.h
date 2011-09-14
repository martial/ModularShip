/*
 *  SimpleCenterReverseGradientAnim.h
 *  LightField
 *
 *  Created by superscript_tower on 29/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef SMPLECENTERGRDTTVSANIM
#define SMPLECENTERGRDTTVSANIM

#include "ofMain.h"
#include "AbstractTubeAnimation.h"
#include "ofxEasingQuint.h"

class SimpleCenterReverseGradientAnim : public  AbstractTubeAnimation {
    
public:
	
    SimpleCenterReverseGradientAnim();
    
    void init(string name, vector<ofxTube*> * tubes);
    void launch();
	
	
    void onAnimationStart(ofxTubeEvent * args);
    void onAnimationEnd(ofxTubeEvent * args);
	void onAnimationLoopEvent(int & a);
    
    void update();
    
    void setEstimatedAnimationTime(float time);
    void quit();
	
	ofxEasingQuint  easingquint;
    
};

#endif