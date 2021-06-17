#pragma once
#include "makejsonThread.h"
#include <thread> 
#include <string>
using namespace std;

int main(int argc, char *argv[]){

    // makejsonThread
    MakeJsonThread mMakeJsonThread;
    thread makejsonThread(&MakeJsonThread::run, &mMakeJsonThread);
    makejsonThread.join();
}