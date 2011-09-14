#pragma once

#include "ofMain.h"
#include "ofxSoundManager.h"
#include "viewThreeD.h"
#include "ofxTubeManager.h"

#include "mainAnimData.h"
#include "ofxColorUtils.h"
#include "guiView.h"
#include "ofxMidiIn.h"
#include "ShipMidiListener.h"


//#include "KinectWrapper.h"
#include "ofxTubeMapping.h"
#include "lfLpdListener.h"
#include "AnimationPreview.h"
#include "oscManager.h"
#include "superInterfacePanel.h"

class testApp : public ofBaseApp {
	public:
	
		void setup();
		void update();
		void draw();
		
		void onTempoEvent (int & a);
		void audioReceived (float * input, int bufferSize, int nChannels);
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		
		void exit();
	


		ofxSoundManager			soundManager;
		superInterfacePanel		interfacePanel;
		//guiCreator				panelCreator;
		
		ofxTubeManager			tubesManager;
		ofxTubeManager			tubesManagerPreview;
	
		AnimationPreview		preview;
	
		guiView					view2D;
		viewThreeD				view3D;
	
		mainAnimData			animData;
		ofxColorUtils			colorUtils;
	
		ofxMidiIn				midiInLpd;
		lfLpdListener			midiListenerLpd;
	
		ofxMidiIn				midiIn;
		ShipMidiListener		midiListener;
	
		oscManager				osc;
		
	
		//KinectWrapper			kinectWrapper;
	
		ofxTubeMapping			tubeMapping;
        
		bool					bDrawPanel;
		bool					bDraw3DView;
	
		
	
		ofImage					mappingPlaceHolder;
	
        //BeatTrackTest               test;
	
		
};
