/*
 *  RandomPixelBlowAnimation.h
 *  ModularShip
 *
 *  Created by Martial Geoffre on 20/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef RDMPXBLW
#define RDMPXBLW

#include "ofMain.h"
#include "AbstractTubeAnimation.h"

class RandomPixelBlowAnimation : public  AbstractTubeAnimation {
    
public:
	
    RandomPixelBlowAnimation();
    
    void init(string name, vector<ofxTube*> * tubes);
    void launch(vector<ofxTube*> * tubes);
	
	
    void onAnimationStart(ofxTubeEvent * args);
    void onAnimationEnd(ofxTubeEvent * args);
	void onAnimationLoopEvent(int & a);
    
    void update();
    
    void setEstimatedAnimationTime(float time);
	
	void onTimerComplete(int & id);
    void quit();
    
};

#endif