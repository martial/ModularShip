#ifndef _THREADED_OBJECT
#define _THREADED_OBJECT

#include "ofMain.h"

// this is not a very exciting example yet
// but ofThread provides the basis for ofNetwork and other
// operations that require threading.
//
// please be careful - threading problems are notoriously hard
// to debug and working with threads can be quite difficult


class threadedObject : public ofThread{

	public:


	    int count;  // threaded fucntions that share data need to use lock (mutex)
	                // and unlock in order to write to that data
	                // otherwise it's possible to get crashes.
	                //
	                // also no opengl specific stuff will work in a thread...
	                // threads can't create textures, or draw stuff on the screen
	                // since opengl is single thread safe
	
		int oldCount;
		int timeElapsed;
		int timerCount;
		
		int			rectActiveTime;
		bool			bdrawRect;
		vector<int>		tempos;
	
		ofEvent<int>	TEMPO_EVENT;

		//--------------------------
		threadedObject(){
			count = 0;
			oldCount = 0.0;
			timeElapsed = 0.0;
			rectActiveTime = 8000; 
		}
	
		void tapTempo () {
			
			if ( tempos.size() > 5 ) {
				tempos.clear();
				for ( int i=0; i<tempos.size(); i++ ) {
					tempos[i] = 0;
				}
				printf("clear vector /");
			}
			
			int currentCount = count;
			timeElapsed = count - oldCount;
			oldCount = currentCount;
			timerCount = 0;
			
			tempos.push_back(timeElapsed);
			
			int total = 0;
			for ( int i=0; i<tempos.size(); i++ ) {
					
				total += tempos[i];
			}
			
			timeElapsed = (int) (total / tempos.size());
			rectActiveTime = (int) timeElapsed / 2;
			bdrawRect = true;
			ofNotifyEvent(TEMPO_EVENT, timerCount, this);
			printf("TFRAMES : %d", timeElapsed);
		
		}

		void start(){
            startThread(true, false);   // blocking, verbose
        }

        void stop(){
            stopThread();
        }

		//--------------------------
		void threadedFunction(){

			while( isThreadRunning() != 0 ){
				if( lock() ){
					
					if ( timerCount >= timeElapsed ) {
							
						bdrawRect = true;
						ofNotifyEvent(TEMPO_EVENT, timerCount, this);
						timerCount = 0;
						printf("go! /");
					}
					
					if ( timerCount > rectActiveTime ) {
						bdrawRect = false;
					}
					
					timerCount ++;
					count++;
					//if(count > 50000) count = 0;
					
					
					
					unlock();
					ofSleepMillis(1 * 30);
				}
			}
		}

		//--------------------------
		void draw(){

			string str = "I am a slowly increasing thread. \nmy current count is: ";

			if( lock() ){
				str += ofToString(count);
				unlock();
			}else{
				str = "can't lock!\neither an error\nor the thread has stopped";
			}
			ofDrawBitmapString(str, 50, 56);
		}
	
	void drawBeat(){
	
		if ( bdrawRect ) {
			ofSetColor(255, 255, 255);
			ofRect(0, 0, 100, 100);
		}
		
	}



};

#endif
