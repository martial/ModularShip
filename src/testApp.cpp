#include "testApp.h"

#define FINAL_APP

//--------------------------------------------------------------
void testApp::setup(){
	
	
	ofSetFrameRate(60);
	
	ofSetLogLevel(OF_LOG_NOTICE);
	
	//kinectWrapper.setup();
	
	ofEnableSmoothing();
	
	//animData.setup("http://www.super-script.com/_modularship/?sequence/liste");
	animData.setup("data.xml");
	tubesManager.setup(&soundManager, &animData, &interfacePanel);
	tubesManager.bKinectMode = false;
	tubesManager.player.id = 999;
	
	ofSoundStreamSetup(0,2,this, 44100, 128, 4);	
	soundManager.setup();
	soundManager.setRangeLimit(1, 8);
	soundManager.setRange(127);
	
	interfacePanel.setup(&tubesManager, &soundManager, &view2D);
	
	
	//panelCreator.setup( &tubesManager, &soundManager, &panel);
	
	
	tubeMapping.init(&tubesManager);
	
	osc.setup(&interfacePanel);
	

	
#ifdef FINAL_APP
	tubesManagerPreview.setup(&soundManager, &animData, &interfacePanel);
	midiListener.setup(&tubesManager,&tubesManagerPreview, &soundManager, &interfacePanel);
	midiIn.listPorts();
	midiIn.openPort(1); 
	midiIn.addListener(&midiListener);
	
	
	 
	

	//panel.parseXML();
	view2D.setup(&soundManager, &tubesManagerPreview);
#endif
	view3D.setup(&soundManager, &tubesManager);
	
	
	bDrawPanel = true;
	bDraw3DView = true;
	
		
	preview.setup(tubesManager.tubes[0]);
	
	mappingPlaceHolder.loadImage("Modular-Ship_mire_3.png");
	
	midiListenerLpd.setup(&tubesManager,&tubesManagerPreview, &soundManager, &interfacePanel);
	midiInLpd.listPorts();
	midiInLpd.openPort(4); 
	midiInLpd.addListener(&midiListenerLpd);
	
	/*
	tapTempo.start();
	ofAddListener(tapTempo.TEMPO_EVENT, this, &testApp::onTempoEvent);
	 */

}

//--------------------------------------------------------------
void testApp::update(){
	//return;
	
	//kinectWrapper.update();
	
	osc.update();
	tubesManager.update();
	
	interfacePanel.update();
	//panelCreator.update();
	
#ifdef FINAL_APP
	
	tubesManagerPreview.update();
	
	view2D.update();
#endif
	
	view3D.update();
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(0,0,0);
	ofSetColor(255, 255, 255);
	
	
#ifdef FINAL_APP
	
	soundManager.debugDraw();
	view2D.draw(0,0);
	if ( bDrawPanel ) interfacePanel.draw();
	if (bDraw3DView ) view3D.draw(500, 115);
	 
#endif
	
#ifndef FINAL_APP
	view3D.draw(0, 115);
#endif
    
   
	//kinectWrapper.debugDraw();
		
	ofPoint offset;
	offset.set(15, 15, 0);
	
	//preview.draw(0, 10);
	//tubeMapping.draw(0,0);
	
	//tubeMapping.debugDraw(0, 100);
	//tubeMapping.draw(1920 +offset.x, offset.y);

	//mappingPlaceHolder.draw(1440+offset.x, offset.y);
	
}


void testApp::onTempoEvent (int & a) {
	
	tubesManager.setAnimation(tubesManager.currentAnimation);
	tubesManagerPreview.setAnimation(tubesManagerPreview.currentAnimation);

}

//--------------------------------------------------------------
void testApp::audioReceived (float * input, int bufferSize, int nChannels){	
	
	soundManager.audioReceived(input, bufferSize);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	//printf("key : %d\n", key);
	
	int yPos;
	
	switch(key) {
		/*
		case 'k':
			if ( kinectWrapper.bStarted ) {
				kinectWrapper.disconnect();
			}
			else {
				kinectWrapper.connect();
			}
			tubesManager.bKinectMode = kinectWrapper.bStarted ;
			break;
				*/
			
		case 32:
			tubesManager.player.resetFrame();
			break;
			
		case 'q':
			view3D.zDiff +=100;
			break;
			
		case 'w':
			view3D.zDiff -=100;
			break;
		
		case 'v':
			bDraw3DView = !bDraw3DView;
			break;
		
		case 'p':
			bDrawPanel = !bDrawPanel;
			break;
		
			/*
		case 32:
			tubesManager.setAnimation(tubesManagerPreview.currentAnimation);
			break;
			*/
			
			
		case 356:
			tubesManager.pushAnimation();
			break;

			
		case 358:
			tubesManager.popAnimation();
			break;
		
		case 'd':
			tubesManager.vAnimationManager.popAnimation();
			break;
			
		case 's':
			tubesManager.vAnimationManager.pushAnimation();
			
			break;
			
		case 'R':
		case 'r':
			soundManager.setup();
			soundManager.setRangeLimit(1, 18);

			break;
			
		case 'N':
		case 'n':
			view3D.nodeGrid.showNumbers = !view3D.nodeGrid.showNumbers;
			break;
			
		case OF_KEY_UP :
			//kinectWrapper.increaseAngle(true);
			break;
			
		case OF_KEY_DOWN :
			//kinectWrapper.increaseAngle(false);
			break;
		
		case 'y':
			tubesManager.vAnimationManager.increaseAnimations(true);
			break;
			
		case 'u':
			tubesManager.vAnimationManager.increaseAnimations(false);
			break;
	
		
		case 'F':
		case 'f':
			ofToggleFullscreen();
			
			//fenster->toggleFullscreen();
			break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    printf("key %d\n", button);

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
    view3D.onWindowsResized(w,h);

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::exit() {
	//kinectWrapper.exit();
}
