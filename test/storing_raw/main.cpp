#pragma once
#include "GpsRawStoringThread.h"
#include <thread> 
#include <string>
using namespace std;

int main(int argc, char *argv[]){

    // GPS
    GpsRawStoringThread mGpsRawStoringThread;
    thread gpsSenderThread(&GpsRawStoringThread::run, &mGpsRawStoringThread);
    gpsSenderThread.join();


}