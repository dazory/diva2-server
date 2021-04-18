#pragma once
#include <iostream>
#include <thread>
#include <zmq.hpp>

#include "../service/global_name.hpp"
//#include "GpsSensingThread.h"
#include "IMU_SensingThread.h"
//#include "CamSensingThread.h"

using namespace std;

/* Global Variables */
int USE_GPS =0; int USE_IMU =0; int USE_CAM =0; int USE_LIDAR =0; int USE_CAN =0; // 1 = REAL, 2 = Test, 0 = Not used
map<string, tuple<string, int>> SensorInfoMap;

int main(int argc, char *argv[]){
    // sudo chmod 777 /dev/ttyACM0
    
    /* Sensing Process */
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_PUB);
    socket.bind(protocol::SENSING_PUB); //protocol::SENSING_PUB);
    printf("bind complete!\n");

    // USE_GPS = 2;
    // GpsSensingThread gpsSensingThread;
    // std::thread sensingthread_gps(gpsSensingThread.run, &socket); // , "/dev/ttyACM0", "9600"

    USE_IMU = 2;
    IMU_SensingThread IMU_SensingProto;
    std::thread sensingthread_IMU(IMU_SensingProto.run, "/dev/ttyACM0", 115200, &socket);
    // USE_CAM = 1;
    // CamSensingThread camSensingThread;
    // std::thread sensingthread_cam(camSensingThread.run, &socket); // , "/dev/ttyACM0", "9600"
    
    sensingthread_IMU.join();
    //sensingthread_gps.join();
    //sensingthread_cam.join();

}