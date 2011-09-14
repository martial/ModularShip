/*
 *  PixelWaveAnim.h
 *  LightField
 *
 *  Created by Martial Geoffre on 17/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PXLWAVEANIM
#define PXLWAVEANIM

#include "ofMain.h"
#include "AbstractTubeAnimation.h"

class PixelWaveAnim : public  AbstractTubeAnimation {
    
public:
	
    PixelWaveAnim();
    
    void init(string name, vector<ofxTube*> * tubes);
    void launch(vector<ofxTube*> * tube);
	
	
    void onAnimationStart(ofxTubeEvent * args);
    void onAnimationEnd(ofxTubeEvent * args);
	void onAnimationLoopEvent(int & a);
    
    void update();
    
    void setEstimatedAnimationTime(float time);
    void quit();
    
};

#endif