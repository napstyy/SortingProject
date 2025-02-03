#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
// im not sure how to draw so i used a mix of the internet and ai for this function
void ofApp::draw() {
    ofBackground(30); // Dark background

    // Draw circles representing numbers
    float spacing = ofGetWidth() / (numbers.size() + 1);
    for (int i = 0; i < numbers.size(); i++) {
        float x = (i + 1) * spacing;
        float y = ofGetHeight() / 2;
        float radius = numbers[i]; // Circle size based on number

        ofSetColor(100, 200, 255);
        ofDrawCircle(x, y, radius);

        // Draw number inside circle
        ofSetColor(255);
        ofDrawBitmapString(ofToString(numbers[i]), x - 10, y + 5);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    switch (key) {
    case 'r':
        generateRandomNumbers();
        break;
    case 'b':
        bubbleSort();
        break;
    case 'i':
        insertionSort();
        break;
    case 'm':
        mergeSort(numbers, 0, numbers.size() - 1);
        break;
    case 'q':
        quickSort(0, numbers.size() - 1);
        break;
    case 's':
        fisherYatesShuffle();
        break;
    default:
        break;
    }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
//--------------------------------------------------------------
void ofApp::generateRandomNumbers() 
{
    numbers.clear();
    for (int i = 0; i < 5; i++) {
        numbers.push_back(ofRandom(10, 100));
    }
}
//--------------------------------------------------------------
// bubble sort goes through the list and swaps positions of numbers until everything is sorted
void ofApp::bubbleSort() {
    int n = numbers.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
            }
        }
    }
}

//--------------------------------------------------------------
// insertion is similar to bubble sorting but it chooses where to insert the number
void ofApp::insertionSort() {
    int n = numbers.size();
    for (int i = 1; i < n; i++) {
        int key = numbers[i];
        int j = i - 1;
        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            j = j - 1;
        }
        numbers[j + 1] = key;
    }
}

//--------------------------------------------------------------
// i used ai for the coding, but i understand that merge sorting is for splitting the sample size in smaller segments then
// adding them up and sorting again
void ofApp::mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

//--------------------------------------------------------------
void ofApp::merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

//--------------------------------------------------------------
// it kinda works like the compass for drawing circles, it picks a number and shoves all the smaller numbers to the left
void ofApp::quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

//--------------------------------------------------------------
int ofApp::partition(int low, int high) {
    int pivot = numbers[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (numbers[j] < pivot) {
            i++;
            swap(numbers[i], numbers[j]);
        }
    }
    swap(numbers[i + 1], numbers[high]);
    return (i + 1);
}

//--------------------------------------------------------------
// random shuffling but it goes backwards
void ofApp::fisherYatesShuffle() {
    int n = numbers.size();
    for (int i = n - 1; i > 0; i--) {
        int j = ofRandom(0, i + 1);
        swap(numbers[i], numbers[j]);
    }
}