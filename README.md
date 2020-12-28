# ofxWitmotion

Witmotion addon for OpenFrameworks
_Special thanks Qaotech Studio_


Ported from the official documentation example C++ code 
https://github.com/WITMOTION/BWT901CL


## Quick example: 

`ofApp.h`

```cpp    
    witmotionController wmc;
```

`ofApp.cpp `

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