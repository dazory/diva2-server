#pragma once
#include <string>
#include <iostream>
#include "IMU_Sensing.h"
#include "../service/zmq_helper.h"

#include "mscl/mscl.h"
//#include <czmq.h>
#include <fstream>
using namespace std;

#define CHUNK_SIZE  250000

extern int USE_IMU;

// class IMUdata {
// public:
//     float gyrox, gyroy, gyroz, magx, magy, magz, accelx, accely, accelz;
// };


class IMU_SensingThread{
	public:
	IMU_SensingThread(){};
	static void run(const char *devicename, mscl::uint32 baudrate, zmq::socket_t *socket);
};

// ImuSensingThread::ImuSensingThread(){

// }

