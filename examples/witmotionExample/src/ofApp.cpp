#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    wmc.setup();
    wmc.setRefreshRate(0x0b);
}

//--------------------------------------------------------------
void ofApp::update(){
    wmc.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(30);
    
    if(!wmc.isConnected){
        ofSetColor(255);
        for(int i = 0; i < wmc.deviceIDs.size(); i++){
            float posY = (i + 1) * 50;
            ofDrawBitmapString("[" + ofToString(i) + "]: " + wmc.deviceIDs[i], 100, posY);
        }
    }else{
        ofPushMatrix();
        ofNoFill();
        ofTranslate(ofGetWidth()*.5, ofGetHeight()*.5, 0);
        
        // rotate
        float* a = wmc.getAngle();
        
        float rX = a[0];
        //rX = ofMap(rX, -180, 180, 0, 360);
        
        float rY = a[1];
        //rY = ofMap(rY, -90, 90, 0, 360);
        
        float rZ = a[2];
        //rZ = ofMap(rZ, -180, 180, 0, 360);
        
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
            ofDrawBitmapString(wmc.gyro[i], 50, (i + 1) * 50);
            ofDrawBitmapString(wmc.acceleration[i], 200, (i + 1) * 50);
            ofDrawBitmapString(wmc.magnetic_field[i], 400, (i + 1) * 50);
            ofDrawBitmapString(wmc.angle[i], 600, (i + 1) * 50);

        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(!wmc.isConnected && key >= 48 && key <= 57) {
        wmc.connectDevice(key - 48);
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
    wmc.tare();
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
