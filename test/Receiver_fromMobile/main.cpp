#pragma once
#include "IMU_receiver.h"
#include <zmq.hpp>
#include <thread>

int main(int argc, char *argv[]){
        // REP
        zmq::context_t contextRep(1);

        //IMU
        IMU_ReceiverThread mImuReceiverThread;
        thread IMU_SenderThread(&IMU_ReceiverThread::run, &mImuReceiverThread, &contextRep);
        IMU_SenderThread.join();

        return 0;
}
