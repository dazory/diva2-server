#pragma once
#include <zmq.hpp>

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
#include <fstream>

#include "mscl/mscl.h"
#include "../service/ImuPacket.h"

using namespace std;

class ImuStoringThread
{
public:
    ImuStoringThread();
    void run(void *); //void ImuStoringThread::run(void *context)
    void stop();

private:
    bool stop_flag = false;
    // float accel_x = 0.1;
    // float accel_y = 0.1;
    // float accel_z = 0.1;
};

ImuStoringThread::ImuStoringThread() {}

void ImuStoringThread::run(void *context)
{
    printf("imu.run (in ImuParsingThread::run)\n");
    zmq::socket_t imu_rep(*(zmq::context_t *)context, ZMQ_REP);
    imu_rep.bind("tcp://*:5564"); //Hmm....... // 172.31.47.43
    printf("imu. Listening (in ImuStoringThread::run)\n");

    ImuPacket mImuPacket;
    while (!stop_flag)
    {
        cout << "while" << endl;
        zmq::message_t ImuData;
        int rc = imu_rep.recv(&ImuData, 0);
        if (rc)
        {
            memcpy(&mImuPacket, ImuData.data(), ImuData.size());
            cout<<"ImuData packet size :" <<ImuData.size()<<endl;
            cout << "memory copy clear!" << endl;

            printf("Accel (X,Y,Z) = (%.2f, %.2f, %.2f)\n", mImuPacket.scaledAccelX, mImuPacket.scaledAccelY, mImuPacket.scaledAccelZ);
            printf("Gyro (X,Y,Z) = (%.2f, %.2f, %.2f)\n", mImuPacket.scaledGyroX, mImuPacket.scaledGyroY, mImuPacket.scaledGyroZ);
            printf("Mag (X,Y,Z) = (%.2f, %.2f, %.2f)\n", mImuPacket.scaledMagX, mImuPacket.scaledMagY, mImuPacket.scaledMagZ);
            printf("est (Roll,Pitch,Yaw) = (%.2f, %.2f, %.2f)\n", mImuPacket.estRoll, mImuPacket.estPitch, mImuPacket.estYaw);
            printf("estUncert (Roll,Pitch,Yaw) = (%.2f, %.2f, %.2f)\n", mImuPacket.estRollUncert, mImuPacket.estPitchUncert, mImuPacket.estYawUncert);
            cout << "recv" << endl;
            string strOK = "thank you";
            zmq::message_t zmqData(sizeof(strOK));
            memcpy(zmqData.data(), strOK.c_str(), sizeof(strOK));
            int ok = imu_rep.send(zmqData, 0);
            if (ok)
                cout << "send ok" << endl;
        }
        else
        {
            string strOK = "recive fail";
            zmq::message_t zmqData(sizeof(strOK));
            memcpy(zmqData.data(), strOK.c_str(), sizeof(strOK));
            int ok = imu_rep.send(zmqData, 0);
            if (ok)
                cout << "send ok" << endl;
        }
        //string str;
        //memcpy(&str,strdata.data(),strdata.size());
        //printf("ANS: %d bytes \n", ImuData.size());

        /*string strOK="thank you";
                zmq::message_t zmqData(sizeof(strOK));
                memcpy(zmqData.data(),strOK.c_str(),sizeof(strOK));
                int ok = imu_rep.send(zmqData,0);
                if(ok)
                        cout<<"send ok"<<endl;*/
    }
    imu_rep.close();
}

void ImuStoringThread::stop()
{
    stop_flag = true;
}
