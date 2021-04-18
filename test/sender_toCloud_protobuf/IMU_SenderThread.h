#pragma once
#include <zmq.hpp>
#include "../service/zmq_helper.h"
#include "../protobuf/sensors.pb.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class IMU_SenderThread{
    public:
        
        IMU_SenderThread(){};
        void run(void *contextSub, zmq::socket_t *socketReq);
    private:
        bool stop_flag=false;
};