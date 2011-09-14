/*
 *  vSimpleAnim.h
 *  ModularShip
 *
 *  Created by superscript_tower on 30/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef VSMPLEANIM
#define VSMPLEANIM

#include "ofMain.h"
#include "AbstractTubeAnimation.h"

class vSimpleAnim : public  AbstractTubeAnimation {
    
public:
	
    vSimpleAnim();
    
    void init(string name, vector<ofxTube*> * tubes);
    void launch(vector<ofxTube*> * tubes);
	
	
    void onAnimationStart(ofxTubeEvent * args);
    void onAnimationEnd(ofxTubeEvent * args);
	void onAnimationLoopEvent(int & a);
    
    void update();
    void quit();
	
    void setEstimatedAnimationTime(float time);
    
    
};

#endif