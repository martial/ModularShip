/*
 *  vLayerAnim.h
 *  LightField
 *
 *  Created by Martial Geoffre on 30/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef VLAYERANIM
#define VLAYERANIM

#include "ofMain.h"
#include "AbstractTubeAnimation.h"
#include "ofxEasingQuint.h"

class vLayerAnim : public  AbstractTubeAnimation {
    
public:
	
    vLayerAnim();
    
    void init(string name, vector<ofxTube*> * tubes);
    void launch(vector<ofxTube*> * tubes);
	
	
    void onAnimationStart(ofxTubeEvent * args);
    void onAnimationEnd(ofxTubeEvent * args);
	void onAnimationLoopEvent(int & a);
    
    void update();
    void quit();
	
    void setEstimatedAnimationTime(float time);
    
	ofxEasingQuint	quint;
	
	int step, sens;
	
    
};

#endif