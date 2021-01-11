//
//  ThreadedWMC.h
//  threadedWitmotionExample
//
//  Created by Dylan Marcus on 1/5/21.
//

#ifndef ThreadedWMC_h
#define ThreadedWMC_h

#include "ofMain.h"
#include <atomic>

class ThreadedWMC: public ofThread
{
public:
    witmotionController wmc;

    ~ThreadedWMC(){
        stop();
        waitForThread(false);
    }

    void setup(){
        wmc.setup();
        wmc.setRefreshRate(0x0b);
        start();
    }

    /// Start the thread.
    void start(){
        startThread();
    }

    void stop(){
        std::unique_lock<std::mutex> lck(mutex);
        stopThread();
        condition.notify_all();
    }

    void threadedFunction(){
        while(isThreadRunning()){
            // since we are only writting to the frame number from one thread
            // and there's no calculations that depend on it we can just write to
            // it without locking
            threadFrameNum++;

            // Lock the mutex until the end of the block, until the closing }
            // in which this variable is contained or we unlock it explicitly
            std::unique_lock<std::mutex> lock(mutex);

            // The mutex is now locked so we can modify
            // the shared memory without problem

            // Now we wait for the main thread to finish
            // with this frame until we can generate a new one
            // This sleeps the thread until the condition is signaled
            // and unlocks the mutex so the main thread can lock it
            condition.wait(lock);
        }
    }

    void update(){
        std::unique_lock<std::mutex> lock(mutex);
        wmc.update();
        condition.notify_all();
    }

    void updateNoLock(){
        condition.notify_all();
    }

    int getThreadFrameNum(){
        return threadFrameNum;
    }
    
protected:
    std::condition_variable condition;
    int threadFrameNum = 0;
};


#endif /* ThreadedWMC_h */
