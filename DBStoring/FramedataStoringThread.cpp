#include "FramedataStoringThread.h"

using namespace std;

FramedataStoringThread::FramedataStoringThread(){}

void FramedataStoringThread::run(){
    char * sql;
   
   
   try {
      connection C("dbname = diva2db user = diva2 password = 1234 \
      hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         //return 1;
      }
      string path = "/home/cvlab2/DIVA2/diva2-server/frame_data.json";
      //string path = "/home/ubuntu/diva2-server/build/test/storing_raw/gps.json";
      //string path = "/home/ubuntu/diva2-server/build/test/receiver_fromMobile_proto/gps.json";

      /* Create SQL statement */
      sql = "create table FRAME_DATA(frame_token text,frame_data_token text,fileformat text, filename text);";
      
      /* Create a transactional object. */
      work W(C);

      /* Execute SQL query */
      W.exec( sql );
      W.commit();

      Json::Value Frame_datas;
      ifstream scene_in(path.c_str());
      if(scene_in.is_open()) scene_in>>Frame_datas;
      cout <<"file open"<<endl;
      std::string temp1;
      std::string temp2;
      std::string temp3;
      std::string temp4;
      cout <<"string"<<endl;
      

      for(int i=0; i<Frame_datas.size(); i++){
      // for (ValueConstIterator it = Gps_datas.begin(); it != Gps_datas.end(); ++it)
      //   {
	     cout<<"for start"<<endl;

         temp3=std::string((Frame_datas[i]["fileformat"].asString()).c_str());
         temp4=std::string((Frame_datas[i]["filename"].asString()).c_str());
         temp1=std::string((Frame_datas[i]["frame_token"].asString()).c_str());
         temp2=std::string((Frame_datas[i]["frame_data_token"].asString()).c_str());

         /* Create a transactional object. */
         work W(C);
	      std::string query_string;
            query_string.append("insert into FRAME_DATA values('"); // *****Set table*****
            query_string.append(temp1);
            query_string.append("','");
            query_string.append(temp2);
            query_string.append("','");
            query_string.append(temp3);
            query_string.append("','");
            query_string.append(temp4);
            query_string.append("');");
         /* Execute SQL query */
         W.exec(query_string);
         W.commit();
	      cout<<"for end"<<endl;
      }
      

      cout << "successfully" << endl;
      C.disconnect ();
   } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
      //return 1;
   }

   //return 0;

}

void FramedataStoringThread::stop(){
    stop_flag = true;
}