#pragma once
#include "LogStoringThread.h"
#include "FrameStoringThread.h"
#include "SceneStoringThread.h"
#include "FramedataStoringThread.h"
#include "LidarStoringThread.h"
#include "CamStoringThread.h"
#include "GpsStoringThread.h"
#include "ImuStoringThread.h"
#include "CanStoringThread.h"

#include <thread> 
#include <string>
using namespace std;

int main(int argc, char *argv[]){

    // LOG
    LogStoringThread mLogStoringThread;
    thread logSenderThread(&LogStoringThread::run, &mLogStoringThread);
    logSenderThread.join();

    // FRAME
    FrameStoringThread mFrameRawStoringThread;
    thread frameSenderThread(&FrameStoringThread::run, &mFrameRawStoringThread);
    frameSenderThread.join();

    // SCENE
    SceneStoringThread mSceneStoringThread;
    thread SceneSenderThread(&SceneStoringThread::run, &mSceneStoringThread);
    SceneSenderThread.join();

    // // FRAMEdata
    // FramedataStoringThread mFramedataStoringThread;
    // thread framedataSenderThread(&FramedataStoringThread::run, &mFramedataStoringThread);
    // framedataSenderThread.join();

    // Lidar
    LidarStoringThread mLidarStoringThread;
    thread lidarSenderThread(&LidarStoringThread::run, &mLidarStoringThread);
    lidarSenderThread.join();

    // CAM
    CamStoringThread mCamStoringThread;
    thread camSenderThread(&CamStoringThread::run, &mCamStoringThread);
    camSenderThread.join();

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
        
}