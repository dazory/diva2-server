#pragma once
#include "ImuStoring.h"
#include <zmq.hpp>
#include <thread>

int main(int argc, char *argv[]){
        // REP
        zmq::context_t contextRep(1);
        ImuStoringThread mImuReceiverThread;
        thread imuSenderThread(&ImuStoringThread::run, &mImuReceiverThread, &contextRep);
        imuSenderThread.join();

        return 0;
}
