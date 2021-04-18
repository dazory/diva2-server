#pragma once
#include "GpsSenderThread.h"
#include "IMU_SenderThread.h"
#include "../service/global_name.hpp"
#include <thread> 
#include <string>

using namespace std;

int USE_GPS =0; int USE_IMU =0; int USE_CAM =0; int USE_LIDAR =0; int USE_CAN =0;

int main(int argc, char *argv[]){
    
    // REQ
    zmq::context_t contextReq(1); 
    zmq::socket_t socketReq(contextReq, ZMQ_REQ);
    socketReq.connect(protocol::SENDER_TOCLOUD_REQ_TEST);//SENDER_TOCLOUD_REQ_TEST
    printf("req socket connected (in main)\n");

    // SUB
    zmq::context_t contextSub(1);
    printf("sub context generated (in main)\n");

    // GPS
    // GpsSenderThread mGpsSenderThread;
    // thread gpsSenderThread(&GpsSenderThread::run, &mGpsSenderThread, &contextSub, &socketReq);
    // gpsSenderThread.join();

    // IMU
    IMU_SenderThread mIMU_Sender;
    thread mIMU_SenderThread(&IMU_SenderThread::run, &mIMU_Sender, &contextSub, &socketReq);
    mIMU_SenderThread.join();

    return 0;

}