#include "IMU_SensingThread.h"
#include "../service/Timestamp.h"
#include <google/protobuf/timestamp.pb.h>
using namespace google;
using namespace protobuf;

void IMU_SensingThread::run(const char *devicename, mscl::uint32 baudrate, zmq::socket_t *socket)
{
    printf("start (MSCL ver: %s)(in IMU_SensingThread::run)\n", mscl::MSCL_VERSION.str());
    //printf("start (MSCL)(in IMU_SensingThread::run)\n");

    IMU_Sensing mIMUSensing;
    //mscl::InertialNode msclNode = mIMUSensing.getMsclNode(devicename, baudrate); //IMU 연결 안되서 오류남
    //printf("imu.getMsclNode (in IMU_SensingThread::run)\n");

    Init();
    sensors::Imu pIMU; //프로토버프에 임의로 생성한 데이터 담기
    float test_data = 0.01;

  
    struct timeval tv;

    while (1)
    {
        s_send_idx(*socket, SENSOR_IMU);
        printf("send index (in IMU_SensingThread::run/while(1))\n");
        // if (USE_IMU == 1)
        // {
        //     mscl::MipDataPackets msclPackets = msclNode.getDataPackets(500);
        //     printf("getDataPackets (in IMU_SensingThread::run/while(1))\n");

        //     for (mscl::MipDataPacket packet : msclPackets)
        //     { //
        //         // printf("MipDataPacket for loop start  (in IMU_SensingThread::run/while(1))\n");

        //         packet.descriptorSet();
        //         mscl::MipDataPoints points = packet.data();
        //         printf("=========== 읽은 데이터 ===========\n");
        //         printf("     Channel     |     Value     \n");
        //         for (mscl::MipDataPoint dataPoint : points)
        //         {
        //             // printf("dataPoint for loop start  (in IMU_SensingThread::run/while(1))\n");
        //             const char *cName = dataPoint.channelName().c_str();
        //             printf("%15s  | %5d : ", cName, ImuMap[cName]);

        //             mIMUSensing.read_imuPacket(ImuMap[cName], dataPoint);
        //         } // End to read a packet line
        //         printf("===========================\n");

        //         printf("=========== 데이터 저장 ===========\n");
        //         mIMUSensing.displayImuPacket();
        //         printf("===========================\n");

        //         s_send_idx(*socket, SENSOR_IMU);
        //         size_t size = mIMUSensing.getImuPacketSize();
        //         zmq::message_t zmqData(size);
        //         ImuPacket mImuPacket = mIMUSensing.getImuPacket();
        //         memcpy(zmqData.data(), &mImuPacket, size);
        //         s_send(*socket, zmqData);
        //         printf("send complete! (in IMU_SensingThread::run/while(1))\n");

        //     } // End to read all packet lines
        // }
        if (USE_IMU == 2)
        {
             
            auto *timestamp = new google::protobuf::Timestamp();  
            gettimeofday(&tv, NULL);
            timestamp->set_seconds(tv.tv_sec + 32400); //UTC to KST
            timestamp->set_nanos(tv.tv_usec * 1000); //마이크로초도 손봐야하나?
            pIMU.set_allocated_timestamp(timestamp); //현제출력 : 2021-04-18T21:30:17.186799Z
            pIMU.set_scaledaccelx(test_data);
            pIMU.set_scaledaccely(test_data);
            pIMU.set_scaledaccelz(test_data);
            pIMU.set_scaledgyrox(test_data);
            pIMU.set_scaledgyroy(test_data);
            pIMU.set_scaledgyroz(test_data);
            pIMU.set_scaledmagx(test_data);
            pIMU.set_scaledmagy(test_data);
            pIMU.set_scaledmagz(test_data);
            pIMU.set_estroll(test_data);
            pIMU.set_estpitch(test_data);
            pIMU.set_estyaw(test_data);
            pIMU.set_estrolluncert(test_data);
            pIMU.set_estpitchuncert(test_data);
            pIMU.set_estyawuncert(test_data);

            int data_len = pIMU.ByteSize();
            cout<<"IMU_SensingThread/ data_len : "<<data_len<<endl;
            unsigned char pBuf[1024] = "\0";
            pIMU.SerializeToArray(pBuf, data_len); 

            for (auto i = 0; i < data_len; i++)
                printf("%02X ", pBuf[i]);
            printf("\n");

            mIMUSensing.Display_protoIMU(pIMU); //

            zmq::message_t zmqData(data_len);
            memcpy((void *)zmqData.data(), pBuf, data_len);
            s_send(*socket, zmqData);
            printf("send complete! (in IMU_SensingThread::run/while(1))\n");

            test_data = test_data + 0.01; //test data 증가시키기. 그냥..안끊기고 잘 오고 저장되나 보려구

            /* OPTION */
            sleep(1);
        }
    }
}

//timestamp->set_seconds(time(NULL)+32400); //UTC to KST
