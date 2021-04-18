#pragma once
#include <zmq.hpp> // https://github.com/zeromq/cppzmq

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <time.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

#include "../service/Linux_keyboard.h"
#include "../service/Strtok_m.h"
#include "../service/Can_serial.h"
#include "../service/Speed_spec.h"
#include "../service/IMU_Packet.h"
#include "mscl/mscl.h"

//#include <google/protobuf/util/time_util.h>
#include <google/protobuf/text_format.h>
#include <google/protobuf/util/json_util.h>
#include "../protobuf/sensors.pb.h"

using namespace std;

class IMU_Sensing{
   public:
      IMU_Sensing();
      mscl::InertialNode getMsclNode(const char *devicename, mscl::uint32 baudrate);
      sensors::Imu read_IMUPacket(int enumIMU, mscl::MipDataPoint dataPoint); //sensors::Imu 으로 리턴 타입 변경
      //void ImuSensing::read_imuPacket(int enumIMU, mscl::MipDataPoint dataPoint);
      void Display_protoIMU(sensors::Imu &pIMU);
      // void display();
      size_t getImuPacketSize();
      size_t getImuPacketsSize();
      ImuPacket getImuPacket();
    
   private:
      ImuPacket mImuPacket;
      vector<ImuPacket> mImuPackets;

};