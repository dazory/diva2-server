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
#include <pqxx/pqxx>

#include "mscl/mscl.h"
#include "../service/ImuPacket.h"

using namespace std;
using namespace pqxx;

class ImuStoringThread
{
public:
    ImuStoringThread();
    void run(void *); //void ImuStoringThread::run(void *context)
    void stop();

private:
    bool stop_flag = false;
};

ImuStoringThread::ImuStoringThread() {}

void ImuStoringThread::run(void *context)
{
    printf("imu.run (in ImuParsingThread::run)\n");
    zmq::socket_t imu_rep(*(zmq::context_t *)context, ZMQ_REP);
    imu_rep.bind("tcp://*:5564"); //165.246.39.124(cvlab2)
    printf("imu. Listening (in ImuStoringThread::run)\n");
    connection C("dbname = ubuntu user = ubuntu password = diva2 \
      hostaddr = 127.0.0.1 port = 5432"); //hostaddr and port?
        if (C.is_open())
            cout << "Connected to " << C.dbname() << endl;
        work W(C); //text : variable unlimited length(=VARCAHR without (n))
        W.exec("create table IMU_DATA(timestamp text, gyro_x text, gyro_y text,gyro_z text, acc_x text, acc_y text,acc_z text,\
         mag_x text, mag_y text,mag_z text, roll text, pitch text, yaw text, roll_uncert text, pitch_uncert text, yaw_uncert text);"); // *****Set table and column*****
        
        //timestamp | gyrox | gyroy | gyroz | accelx | accely | accelz |  magx | magy | magz | roll | pitch | yaw | rolluncert | pitchuncert | yawuncert

    ImuPacket mImuPacket;
    while (!stop_flag)
    {
        cout << "while" << endl;
        zmq::message_t ImuData;

        int rc = false;
        rc = imu_rep.recv(&ImuData, 0);

        if (rc)
        {
            memcpy(&mImuPacket, ImuData.data(), ImuData.size());
            cout<<"ImuData packet size :" <<ImuData.size()<<endl;

            // Execute SQL query : Storing IMU Data(raw) to DB
            string query_string = "insert IMU_DATA(";
            query_string.append(to_string(mImuPacket.time));
            query_string.append("', ");
            query_string.append(to_string(mImuPacket.scaledGyroX));
            query_string.append(", ");
            query_string.append(to_string(mImuPacket.scaledGyroY));
            query_string.append(", ");
            query_string.append(to_string(mImuPacket.scaledGyroZ));
            query_string.append(", ");
            query_string.append(to_string(mImuPacket.scaledAccelX));
            query_string.append(", ");
            query_string.append(to_string(mImuPacket.scaledAccelY));
            query_string.append(", ");
            query_string.append(to_string(mImuPacket.scaledAccelZ));
            query_string.append(", ");
            query_string.append(to_string(mImuPacket.scaledMagX));
            query_string.append(", ");
            query_string.append(to_string(mImuPacket.scaledMagY));
            query_string.append(", ");
            query_string.append(to_string(mImuPacket.scaledMagZ));
            query_string.append(", ");
            query_string.append(to_string(mImuPacket.estRoll));
            query_string.append(", ");
            query_string.append(to_string(mImuPacket.estYaw));
            query_string.append(", ");
            query_string.append(to_string(mImuPacket.estPitch));
            query_string.append(", ");
            query_string.append(to_string(mImuPacket.estRollUncert));
            query_string.append(", ");
            query_string.append(to_string(mImuPacket.estPitchUncert));
            query_string.append(", ");
            query_string.append(to_string(mImuPacket.estYawUncert));
            query_string.append(");");
            W.exec(query_string);
            W.commit();
            std::cout << "IMU_DATA storing to DB" <<endl;

            //~~~~~~~~~ check the packet ~~~~~~~~~~
            // printf("Gyro (X,Y,Z) = (%.2f, %.2f, %.2f)\n", mImuPacket.scaledGyroX, mImuPacket.scaledGyroY, mImuPacket.scaledGyroZ);
            // printf("Accel (X,Y,Z) = (%.2f, %.2f, %.2f)\n", mImuPacket.scaledAccelX, mImuPacket.scaledAccelY, mImuPacket.scaledAccelZ);
            // printf("Mag (X,Y,Z) = (%.2f, %.2f, %.2f)\n", mImuPacket.scaledMagX, mImuPacket.scaledMagY, mImuPacket.scaledMagZ);
            // printf("est (Roll,Pitch,Yaw) = (%.2f, %.2f, %.2f)\n", mImuPacket.estRoll, mImuPacket.estPitch, mImuPacket.estYaw);
            // printf("estUncert (Roll,Pitch,Yaw) = (%.2f, %.2f, %.2f)\n", mImuPacket.estRollUncert, mImuPacket.estPitchUncert, mImuPacket.estYawUncert);
            //cout << "recv" << endl; 

            //~~~ send OK msg to Mobile ~~~
            string strOK = "thank you";
            zmq::message_t zmqData(sizeof(strOK));
            memcpy(zmqData.data(), strOK.c_str(), sizeof(strOK));
            int ok = imu_rep.send(zmqData, 0);
            if (ok)
                cout << "send ok" << endl;
        }
        else //receive failed -> send not ok msg to Mobile 
        {
            string strNotOk = "receive failed";
            zmq::message_t zmqData(sizeof(strNotOk));
            memcpy(zmqData.data(), strNotOk.c_str(), sizeof(strNotOk));
            int NotOk = imu_rep.send(zmqData, 0);
            if (NotOk)
                cout << "waiting...." << endl;
        }
        
    }
    imu_rep.close();
}

void ImuStoringThread::stop()
{
    stop_flag = true;
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