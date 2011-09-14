/*
 *  vDualBlinkAnim.h
 *  ModularShip
 *
 *  Created by superscript_tower on 31/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef VDUALBLINKANIM
#define VDUALBLINKANIM

#include "ofMain.h"
#include "AbstractTubeAnimation.h"
#include "ofxEasingQuint.h"

class vDualBlinkAnim : public  AbstractTubeAnimation {
    
public:
	
    vDualBlinkAnim();
    
    void init(string name, vector<ofxTube*> * tubes);
    void launch(vector<ofxTube*> * tubes);
	
	
    void onAnimationStart(ofxTubeEvent * args);
    void onAnimationEnd(ofxTubeEvent * args);
	void onAnimationLoopEvent(int & a);
    
    void update();
    void quit();
	
    void setEstimatedAnimationTime(float time);
    
	ofxEasingQuint	quint;
	bool bIncrease;
    
};

#endif