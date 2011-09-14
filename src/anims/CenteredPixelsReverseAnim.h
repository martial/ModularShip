/*
 *  CenteredPixelsReverseAnim.h
 *  LightField
 *
 *  Created by Martial Geoffre on 17/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CTRDPRVRSXANIM
#define CTRDPRVRSXANIM

#include "ofMain.h"
#include "AbstractTubeAnimation.h"
#include "ofxTween.h"
#include "ofxEasingQuint.h"

class CenteredPixelsReverseAnim : public  AbstractTubeAnimation {
    
public:
	
    CenteredPixelsReverseAnim();
    
    void init(string name, vector<ofxTube*> * tubes);
    void launch();
	
	
    void onAnimationStart(ofxTubeEvent * args);
    void onAnimationEnd(ofxTubeEvent * args);
	void onAnimationLoopEvent(int & a);
    
    void update();
    
    void setEstimatedAnimationTime(float time);
	void quit();
	
	private :
	
	
	int						pixelIndex, numOfTubePixels;
	int						middle;
	ofxTween				pixelTween;
	ofxEasingQuint			easingquint;
    
    
};

#endif