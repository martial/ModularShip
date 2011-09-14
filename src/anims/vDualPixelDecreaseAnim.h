/*
 *  vDualPixelDecreaseAnim.h
 *  ModularShip
 *
 *  Created by superscript_tower on 30/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef VDUALDCRPIXELANIM
#define VDUALDCRPIXELANIM

#include "ofMain.h"
#include "AbstractTubeAnimation.h"
#include "ofxEasingQuint.h"

class vDualPixelDecreaseAnim : public  AbstractTubeAnimation {
    
public:
	
    vDualPixelDecreaseAnim();
    
    void init(string name, vector<ofxTube*> * tubes);
    void launch(vector<ofxTube*> * tubes);
	
	
    void onAnimationStart(ofxTubeEvent * args);
    void onAnimationEnd(ofxTubeEvent * args);
	void onAnimationLoopEvent(int & a);
    
    void update();
    void quit();
	
    void setEstimatedAnimationTime(float time);
    
	ofxEasingQuint	quint;
    
};

#endif