#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(200);
    threadedwmc.setup();
    threadedwmc.start();
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(30);
    
    if(!threadedwmc.wmc.isConnected){
        ofSetColor(255);
        for(int i = 0; i < threadedwmc.wmc.deviceIDs.size(); i++){
            float posY = (i + 1) * 50;
            ofDrawBitmapString("[" + ofToString(i) + "]: " + threadedwmc.wmc.deviceIDs[i], 100, posY);
        }
    }else{
        ofPushMatrix();
        ofNoFill();
        ofTranslate(ofGetWidth()*.5, ofGetHeight()*.5, 0);
        
        // rotate
        float* a = threadedwmc.wmc.getAngle();
        
        float rX = a[0];
        float rY = a[1];
        float rZ = a[2];
        
        ofRotateXDeg(rX);
        ofRotateYDeg(rY);
        ofRotateZDeg(rZ);

        ofDrawBox(0, 0, 0, 200);
        ofPopMatrix();
 
        // information text
        ofSetColor(255);
        ofDrawBitmapString("Gyro", 50, 20);
        ofDrawBitmapString("Acc", 200, 20);
        ofDrawBitmapString("Magnetic", 400, 20);
        ofDrawBitmapString("Angle", 600, 20);

        for(int i =0; i < 3; i++){
            ofDrawBitmapString(threadedwmc.wmc.gyro[i], 50, (i + 1) * 50);
            ofDrawBitmapString(threadedwmc.wmc.acceleration[i], 200, (i + 1) * 50);
            ofDrawBitmapString(threadedwmc.wmc.magnetic_field[i], 400, (i + 1) * 50);
            ofDrawBitmapString(threadedwmc.wmc.angle[i], 600, (i + 1) * 50);
        }
    }
    
    auto threadFrame = threadedwmc.getThreadFrameNum();
    ofSetColor(255,0,0);
    ofDrawBitmapString("app frame: " + ofToString(ofGetFrameNum()), 20,20);
    ofDrawBitmapString("thread frame: " + ofToString(threadFrame), 20,35);
    ofDrawBitmapString("diff: " + ofToString(int64_t(ofGetFrameNum()) - threadFrame), 20,50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(!threadedwmc.wmc.isConnected && key >= 48 && key <= 57) {
        threadedwmc.wmc.connectDevice(key - 48);
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
    //reset orientation
    threadedwmc.wmc.recenter();
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
