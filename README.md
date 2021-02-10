# ofxWitmotion

Witmotion addon for OpenFrameworks

_Development Support and special thanks Qaotech Studio_


Ported from the official documentation example C++ code 
https://github.com/WITMOTION/BWT901CL


## Quick example:

`ofApp.h`

```cpp    
    witmotionController wmc;
```

`ofApp.cpp`

```cpp
    // in ofApp::setup()
    wmc.setup();
    wmc.connectDevice(int DEVICE_ID);
    
    // in ofApp::update()
    wmc.update();
    wmc.getAcceleration();
    wmc.getGyro();
    wmc.getAngle();
    wmc.getMagneticField();
```

## Device Setup
 - Change the broadcast name of the HC-06/HC-05 from manufacturing side
 - set the passcode to `0000` so it pairs by default, the default passcode for WitMotion currently is `1234`
 - Change the default refresh rate of the device to `200hz` 

## TODO
 - Figure out improvements to drift
