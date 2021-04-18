#include "IMU_receiver.h"

void IMU_ReceiverThread::run(void *context)
{
    printf("IMU.run (in IMU_ReceiverThread::run)\n");
    zmq::socket_t IMU_rep(*(zmq::context_t *)context, ZMQ_REP);
    IMU_rep.bind("tcp://*:5564"); //165.246.39.124(cvlab2)
    printf("IMU. Listening (in IMU_ReceiverThread::run)\n");

    //ImuPacket mImuPacket; //class type
    sensors::Imu pIMU; //프로토 버퍼
    while (!stop_flag)
    {
        cout << "while" << endl;
        zmq::message_t IMU_Data;

        int rc = false;
        rc = IMU_rep.recv(&IMU_Data); //패킷을 못받으면 return을 할때까지 머물러 있기 때문에
        cout << "received at : " << ts.p_time() << endl;

        if (rc = true)
        {
            pIMU.ParseFromArray(IMU_Data.data(), IMU_Data.size());       //parseformarray?
            cout << "IMU_Data packet size :" << IMU_Data.size() << endl; //아니 사이즈 76나옴. 클래스로 보낼때보다 더 많은데.....
            
            //json으로 변환 -> time 측정 & 비교
            string json_string;
            google::protobuf::util::JsonPrintOptions options;
            options.add_whitespace = true;
            options.always_print_primitive_fields = true;
            options.preserve_proto_field_names = true;
            google::protobuf::util::MessageToJsonString(pIMU, &json_string, options);
            cout << json_string << endl;
            cout << "MessageToJson at : " << ts.p_time() << endl;

            //json 파일 생성 및 서버에 저장
            std::ofstream ost;
            ost.open("IMU.json", std::ios_base::out | std::ios_base::app);
            ost << json_string;
            cout << "saved" << endl <<endl;

            //~~~ send OK msg to Mobile ~~~
            string strOK = "thank you";
            zmq::message_t zmqData(sizeof(strOK));
            memcpy(zmqData.data(), strOK.c_str(), sizeof(strOK));
            int ok = IMU_rep.send(zmqData, 0);
            if (ok)
                cout << "send ok" << endl;
        }
        else if (rc = false) //receive failed -> send not ok msg to Mobile
        {
            string strNotOk = "receive failed";
            zmq::message_t zmqData(sizeof(strNotOk));
            memcpy(zmqData.data(), strNotOk.c_str(), sizeof(strNotOk));
            int NotOk = IMU_rep.send(zmqData, 0);
            if (NotOk)
                cout << "waiting...." << endl;
        }
    }
    IMU_rep.close();
}

void IMU_ReceiverThread::stop()
{
    stop_flag = true;
}

////json과 비슷하지만 그냥 변수 : value 로 나옴
// string strTxt;
// google::protobuf::TextFormat::PrintToString(pIMU, &strTxt);
// cout << strTxt << endl;

//mImuPacket.display();
//~~~~~~~~~ check the packet (Class) ~~~~~~~~~~
// printf("Accel (X,Y,Z) = (%.2f, %.2f, %.2f)\n", mImuPacket.scaledAccelX, mImuPacket.scaledAccelY, mImuPacket.scaledAccelZ);
// printf("Gyro (X,Y,Z) = (%.2f, %.2f, %.2f)\n", mImuPacket.scaledGyroX, mImuPacket.scaledGyroY, mImuPacket.scaledGyroZ);
// printf("Mag (X,Y,Z) = (%.2f, %.2f, %.2f)\n", mImuPacket.scaledMagX, mImuPacket.scaledMagY, mImuPacket.scaledMagZ);
// printf("est (Roll,Pitch,Yaw) = (%.2f, %.2f, %.2f)\n", mImuPacket.estRoll, mImuPacket.estPitch, mImuPacket.estYaw);
// printf("estUncert (Roll,Pitch,Yaw) = (%.2f, %.2f, %.2f)\n", mImuPacket.estRollUncert, mImuPacket.estPitchUncert, mImuPacket.estYawUncert);

// cout << "recv" << endl;

// connection C("dbname = ubuntu user = ubuntu password = diva2 \
    //   hostaddr = 127.0.0.1 port = 5432"); //hostaddr and port?
//     if (C.is_open())
//         cout << "Connected to " << C.dbname() << endl;
//     work W(C); //text : variable unlimited length(=VARCAHR without (n))
//     W.exec("create table IMU_DATA(timestamp text, gyro_x text, gyro_y text,gyro_z text, acc_x text, acc_y text,acc_z text,\
    //      mag_x text, mag_y text,mag_z text, roll text, pitch text, yaw text, roll_uncert text, pitch_uncert text, yaw_uncert text);"); // *****Set table and column*****

//timestamp | gyrox | gyroy | gyroz | accelx | accely | accelz |  magx | magy | magz | roll | pitch | yaw | rolluncert | pitchuncert | yawuncert

// // Execute SQL query : Storing IMU Data(raw) to DB
// string query_string = "insert IMU_DATA(";
// query_string.append(to_string(mImuPacket.time));
// query_string.append("', ");
// query_string.append(to_string(mImuPacket.scaledGyroX));
// query_string.append(", ");
// query_string.append(to_string(mImuPacket.scaledGyroY));
// query_string.append(", ");
// query_string.append(to_string(mImuPacket.scaledGyroZ));
// query_string.append(", ");
// query_string.append(to_string(mImuPacket.scaledAccelX));
// query_string.append(", ");
// query_string.append(to_string(mImuPacket.scaledAccelY));
// query_string.append(", ");
// query_string.append(to_string(mImuPacket.scaledAccelZ));
// query_string.append(", ");
// query_string.append(to_string(mImuPacket.scaledMagX));
// query_string.append(", ");
// query_string.append(to_string(mImuPacket.scaledMagY));
// query_string.append(", ");
// query_string.append(to_string(mImuPacket.scaledMagZ));
// query_string.append(", ");
// query_string.append(to_string(mImuPacket.estRoll));
// query_string.append(", ");
// query_string.append(to_string(mImuPacket.estYaw));
// query_string.append(", ");
// query_string.append(to_string(mImuPacket.estPitch));
// query_string.append(", ");
// query_string.append(to_string(mImuPacket.estRollUncert));
// query_string.append(", ");
// query_string.append(to_string(mImuPacket.estPitchUncert));
// query_string.append(", ");
// query_string.append(to_string(mImuPacket.estYawUncert));
// query_string.append(");");
// W.exec(query_string);
// W.commit();
// std::cout << "IMU_DATA storing to DB" <<endl;

//string str;
//memcpy(&str,strdata.data(),strdata.size());
//printf("ANS: %d bytes \n", ImuData.size());

/*string strOK="thank you";
                zmq::message_t zmqData(sizeof(strOK));
                memcpy(zmqData.data(),strOK.c_str(),sizeof(strOK));
                int ok = imu_rep.send(zmqData,0);
                if(ok)
                        cout<<"send ok"<<endl;*/