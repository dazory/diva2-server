#include "CamReceiverThread.h"
#include "../service/Timestamp.h"
#include "../service/global_name.hpp"
#include "../service/gps_packet.h"
#include "../protobuf/sensors.pb.h"
#include <fstream>
#include "jsoncpp/json/json.h"
#pragma comment(lib, "jsoncpp\\lib\\lib_json.lib")
#pragma warning(disable : 4996) //error C4996 뜨는 경우

#include <google/protobuf/text_format.h>
#include <google/protobuf/util/json_util.h>

#define PACKET_SIZE 1024
using namespace std;

CamReceiverThread::CamReceiverThread(){}

void CamReceiverThread::run(void *contextRep){
    printf("start (in GpsReceiverThread::run)\n");
    
    // Connect with socket REP with SenderTocloud
    zmq::socket_t socketRep(*(zmq::context_t*)contextRep, ZMQ_REP);
    printf("socketRep\n");
    socketRep.bind(protocol::RECEIVER_FROMMOBILE_REP_TEST); 
    printf("connect\n");
    printf("socket connected (in CamReceiverThread::run)\n");

    while(1){//!stop_flag){
        printf("while(1) start! (in CamReceiverThread::run/while(1))\n");
		
        /* RECIEVE FROM MOBILE */
        zmq::message_t msgData;
        socketRep.recv(&msgData);
        printf("Recevied (in CamReceiverThread::run/while(1))\n");

        sensors::Cam cam;
        /*unsigned char data[1024] = "\0";
        gps.ParseFromArray(msgData.data(), msgData.size());

        string strTxt;
        google::protobuf::TextFormat::PrintToString(gps, &strTxt);
        cout<<strTxt<<" (in GpsReceiverThread::run/while(1))"<<endl;
        */
        /* SEND REPLY TO MOBILE */
        /*string strOK = "THANK YOU";
        zmq::message_t zmqData(sizeof(strOK));
        memcpy(zmqData.data(), strOK.c_str(), sizeof(strOK));
        s_send(socketRep, zmqData);
        */
        /* CONVERT PROTO TO JSON */
        /* ========== 가연이 것 ==================*/
        string str;
        Json::Value cam_json;
        //cam_json["latitude"] = cam.latitude();
        //cam_json["longtitude"] = cam.longitude();
        Json::Value data_json;
        data_json.append(cam_json);

        Json::StyledWriter writer;
        str = writer.write(cam_json);
        cout << str << endl;
        
        /*
        string json_string;
        google::protobuf::util::JsonPrintOptions options;
        options.add_whitespace = true;
        options.always_print_primitive_fields = true;
        options.preserve_proto_field_names = true;
        google::protobuf::util::MessageToJsonString(gps, &json_string, options);
        cout<<json_string<<endl;
        */ 

        std::ofstream ost;
        ost.open("cam.json",std::ios_base::out | std::ios_base::app);
        ost << str;

        
        /* OPTIONS */

    }

}

void CamReceiverThread::stop(){
    stop_flag = true;
}