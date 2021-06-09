#include "makejsonThread.h"

using namespace std;

MakeJsonThread::MakeJsonThread(){}

void MakeJsonThread::run(){
    MakeJson* j = new MakeJson("/home/kayeon/Downloads/DIVA_DATA");
    j->Sensor(5);
    j->Log(0);
    j->Frame();
    j->Scene();
    j->Frame_Data();
    j->Gps_Data();
    j->Imu_Data();
    j->Can_Data();

    delete j;
   //  return 0;
}

void MakeJsonThread::stop(){
    stop_flag = true;
}