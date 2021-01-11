#pragma once

#include "ofMain.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <termios.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <sys/types.h>
#include <errno.h>

#define BAUD 115200

class witmotionController {
public: 
    
    witmotionController();
    ~witmotionController();
    
    void setup();
    void update();
    
    // returns available bluetooth devices
    vector <string> getDeviceIDs();

    // data receiving & parsing functions
    int recvData(char *recv_buffer, int length);
    void parseData(char chr);
    
    // serial connection functions
    void connectDevice(int deviceID);
    void disconnectDevice();
    
    // get functions for data
    float* getAcceleration();
    float* getGyro();
    float* getAngle();
    float* getMagneticField();
    
    // serial 
    ofSerial serial;
    vector <ofSerialDeviceInfo> deviceList;
    vector <string> deviceIDs;
    
    int ret, fd;
    
    //acceleration
    float acceleration[3];
    
    //gyroscope
    float gyro[3];
    
    //angle
    float angle[3];
    
    //magnetic field
    float magnetic_field[3];

    //reset orientation
    float magnetic_field_shift[3];
    float acceleration_shift[3];
    float gyro_shift[3];
    float angle_shift[3];
    void resetOrientation();
    void tare();
    void setRefreshRate(int rate);
    void calibrateDevice();
    
    char r_buf[1024];
    
    // to check if a device connected currently
    bool isConnected;
};
