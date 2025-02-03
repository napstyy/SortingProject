#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		vector<int> numbers; // store the 5 random numbers

		void generateRandomNumbers();
		void bubbleSort();
		void insertionSort();
		void mergeSort(vector<int>& arr, int left, int right);
		void merge(vector<int>& arr, int left, int mid, int right);
		void quickSort(int low, int high);
		int partition(int low, int high);
		void fisherYatesShuffle();







};
