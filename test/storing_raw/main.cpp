#pragma once
//#include "GpsRawStoringThread.h"
// #include "readfiles.h"
// #include "indexandtimes.h"
// #include "makejson.h"
// #include "GpscsvRawStoringThread.h"
#include "makejsonThread.h"
#include <thread> 
#include <string>
using namespace std;

int main(int argc, char *argv[]){

    // // GPS
    // GpsRawStoringThread mGpsRawStoringThread;
    // thread gpsSenderThread(&GpsRawStoringThread::run, &mGpsRawStoringThread);
    // gpsSenderThread.join();

    // makejsonThread
    MakeJsonThread mMakeJsonThread;
    thread makejsonSenderThread(&MakeJsonThread::run, &mMakeJsonThread);
    makejsonSenderThread.join();

    // MakeJson* j = new MakeJson("/home/kayeon/Downloads/DIVA_DATA");
    // j->Sensor(5);
    // j->Log(0);
    // j->Frame();
    // j->Scene();
    // j->Frame_Data();
    // j->Gps_Data();
    // j->Imu_Data();
    // j->Can_Data();

    // delete j;
    // return 0;

    // GPS csv
    // GpsRawStoringThread mGpsRawStoringThread;
    // thread gpsSenderThread(&GpsRawStoringThread::run, &mGpsRawStoringThread);
    // gpsSenderThread.join();


}