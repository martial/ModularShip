/*
 *  InverseCenteredPixelsAnim.h
 *  ModularShip
 *
 *  Created by superscript_tower on 25/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INVCETREDPIXELANIM
#define INVCETREDPIXELANIM

#include "ofMain.h"
#include "AbstractTubeAnimation.h"
#include "ofxTween.h"
#include "ofxEasingQuint.h"

class InverseCenteredPixelsAnim : public  AbstractTubeAnimation {
    
public:
	
    InverseCenteredPixelsAnim();
    
    void init(string name, vector<ofxTube*> * tubes);
    void launch(vector<ofxTube*> * tubes);
	
	
    void onAnimationStart(ofxTubeEvent * args);
    void onAnimationEnd(ofxTubeEvent * args);

	void onAnimationLoopEvent(int & a);
    
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