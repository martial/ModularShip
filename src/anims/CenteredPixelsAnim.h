/*
 *  CenteredPixelsAnim.h
 *  LightField
 *
 *  Created by Martial Geoffre on 13/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CTRDPXANIM
#define CTRDPXANIM

#include "ofMain.h"
#include "AbstractTubeAnimation.h"
#include "ofxTween.h"
#include "ofxEasingQuint.h"

class CenteredPixelsAnim : public  AbstractTubeAnimation {
    
public:
	
    CenteredPixelsAnim();
    
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