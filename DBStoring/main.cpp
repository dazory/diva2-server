#pragma once
#include "GpsStoringThread.h"
#include "ImuStoringThread.h"

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

    

        
}