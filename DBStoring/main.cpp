#pragma once
#include "GpsStoringThread.h"
#include "ImuStoringThread.h"
#include "CanStoringThread.h"
#include "LogStoringThread.h"

#include <thread> 
#include <string>
using namespace std;

int main(int argc, char *argv[]){
    // GPS
    GpsStoringThread mGpsStoringThread;
    thread gpsSenderThread(&GpsStoringThread::run, &mGpsStoringThread);
    gpsSenderThread.join();

    // IMU
    ImuStoringThread mImuStoringThread;
    thread imuSenderThread(&ImuStoringThread::run, &mImuStoringThread);
    imuSenderThread.join();

    // CAN
    CanStoringThread mCanStoringThread;
    thread canSenderThread(&CanStoringThread::run, &mCanStoringThread);
    canSenderThread.join();

    // LOG
    LogStoringThread mLogStoringThread;
    thread logSenderThread(&LogStoringThread::run, &mLogStoringThread);
    logSenderThread.join();


    

        
}