#include "IMU_SenderThread.h"

void IMU_SenderThread::run(void *contextSub, zmq::socket_t *socketReq)
{
    printf("start (in GpsSenderThread::run)\n");

    // Connect with socket SUB with Sensing Process
    zmq::socket_t socketSub(*(zmq::context_t *)contextSub, ZMQ_SUB);
    socketSub.connect(protocol::SENSING_SUB);
    socketSub.setsockopt(ZMQ_SUBSCRIBE, "IMU", 3);
    printf("socket connected (in IMU_SenderThread::run)\n");

    while(1){
        sensors::Imu pIMU;
        zmq::message_t msgData;
        socketSub.recv(&msgData);
        printf("Recevied (in IMU_SenderThread::run)\n");

        //unsigned char data[1024] = "\0";
        pIMU.ParseFromArray(msgData.data(), msgData.size());

        /* SEND TO CLOUD SERVER */
        int data_len = pIMU.ByteSize();
        cout<<"IMU_SenderThread/ data_len : "<<data_len<<endl;
        unsigned char data[1024] = "\0";
        pIMU.SerializeToArray(data, data_len);
        for (auto i = 0; i < data_len; i++)
            printf("%02X ", data[i]);
        printf("\n");

        size_t size = data_len;
        zmq::message_t zmqDatas(size);
        // memcpy((void*)zmqDatas.data(), strMsg.c_str(), size);
        memcpy((void *)zmqDatas.data(), data, size);
        printf("Sending IMU data ...\n");
        s_send(*socketReq, zmqDatas); //flag를 1로 추가해봄(0) -> flag를 2로 추가해봄(x)
        printf("send complete!\n");

        /* OPTIONAL: DELETE ALL GLOBAL OBJECTS ALLOCATED BY LIBPROTOBUF */
        google::protobuf::ShutdownProtobufLibrary();

        /* RECEIVE FROM CLOUD SERVER PROCESS */
        zmq::message_t msgRecv = s_recv(*socketReq);
        printf("Reply:%s\n", msgRecv.data());
        printf("size=%d (IMU:%d)\n", zmqDatas.size(), size);
    }
}
