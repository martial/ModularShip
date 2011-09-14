/*
 *  SimpleCenterGradientAnim.h
 *  LightField
 *
 *  Created by superscript_tower on 29/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SMPLECENTERGRDTVSANIM
#define SMPLECENTERGRDTVSANIM

#include "ofMain.h"
#include "AbstractTubeAnimation.h"
#include "ofxEasingQuint.h"

class SimpleCenterGradientAnim : public  AbstractTubeAnimation {
    
public:
	
    SimpleCenterGradientAnim();
    
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