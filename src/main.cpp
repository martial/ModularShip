#include "ofMain.h"
#include "ofAppGlutWindow.h"
#include "testApp.h"

int main() {
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1400, 900, OF_FULLSCREEN);
	
	
	testApp* app = new testApp;
	
		
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( app );	
}
