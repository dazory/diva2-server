// 참고: https://github.com/kka-na/DIVA_Qt

#include "makejsonThread.h"

using namespace std;

MakeJsonThread::MakeJsonThread(){}

void MakeJsonThread::run(){

    time_t system_time;
    struct tm* systime;
    system_time = time(NULL);
    systime = localtime(&system_time);

    string tm_year = to_string(systime->tm_year + 1900);
    string tm_month = to_string(systime->tm_mon+1);
    string tm_date = to_string(systime->tm_mday);
    if(tm_date.size() == 1){
        tm_date = "0"+tm_date;
    }

    string timestamp;
    timestamp = tm_year + tm_month + tm_date;

    MakeJson* j = new MakeJson("/home/cvlab2/DIVA2/diva2-server/DIVA2_DATA/"+timestamp+"_0");
    j->Sensor(5);
    j->Log(0);
    j->Frame();
    j->Scene();
    j->Lidar_Data();
    j->Cam_Data();
    j->Gps_Data();
    j->Imu_Data();
    j->Can_Data();

    delete j;
}

void MakeJsonThread::stop(){
    stop_flag = true;
}