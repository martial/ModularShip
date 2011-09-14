/*
 *  SimpleAnim.h
 *  ModularShip
 *
 *  Created by Martial Geoffre on 11/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SMPLEANIM
#define SMPLEANIM

#include "ofMain.h"
#include "AbstractTubeAnimation.h"

class SimpleAnim : public  AbstractTubeAnimation {
    
public:
	
    SimpleAnim();
    
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