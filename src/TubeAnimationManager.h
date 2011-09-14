//
//  TubeAnimationManager.h
//  LightField
//
//  Created by Martial Geoffre on 03/05/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


#ifndef TBANIMMNGR
#define TBANIMMNGR

#include "ofMain.h"
#include "AbstractTubeAnimation.h"
#include "ofxTube.h"
#include "ofxTubeEvent.h"
#include "ofxAnimPlayer.h"

class TubeAnimationManager {
    
  public:
    
    TubeAnimationManager();
    void setup(vector<ofxTube*> * tubes, ofxAnimPlayer * player);
    void setAnimations();
    void update();
    
	void reset();
	void increaseAnimations (bool bIncreasing);
	void pushAnimation();
	void popAnimation();
    void setCurrentAnimationById(int num);
	void setDecayTimePct(float val);

    
	void onAnimationLoopEvent(int & a) ;
	void onActiveEvent(ofxTubeEvent & args);
    
    vector<AbstractTubeAnimation*>      animations;
	int									mode;
	float								decayTimePct;
	int									currentAnimId;
	
	AbstractTubeAnimation			*	currentAnimation;
	
    private:
    
	vector<ofxTube*>				*	tubes;
    
	
	
	ofxAnimPlayer					*	player;
	
	bool								bLaunchNextFrame;
	int									oldMode;
};

#endif