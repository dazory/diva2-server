#include "makejsonThread.h"

using namespace std;

MakeJsonThread::MakeJsonThread(){}

void MakeJsonThread::run(){
    MakeJson* j = new MakeJson("/home/cvlab2/DIVA2/diva2-server/DIVA2data/2021615_0");
    j->Sensor(5);
    j->Log(0);
    j->Frame();
    j->Scene();
    // j->Frame_Data();

    j->Lidar_Data();
    j->Cam_Data();
    j->Gps_Data();
    j->Imu_Data();
    j->Can_Data();

    delete j;
   //  return 0;
}

void MakeJsonThread::stop(){
    stop_flag = true;
}