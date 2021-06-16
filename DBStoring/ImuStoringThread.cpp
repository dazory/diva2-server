#include "ImuStoringThread.h"

using namespace std;

ImuStoringThread::ImuStoringThread(){}

void ImuStoringThread::run(){
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
      string path = "/home/cvlab2/DIVA2/diva2-server/DIVA2data/2021615_0/JSON/imu_data.json";
      //string path = "/home/ubuntu/diva2-server/build/test/storing_raw/gps.json";
      //string path = "/home/ubuntu/diva2-server/build/test/receiver_fromMobile_proto/gps.json";

      /* Create SQL statement */
      sql = "create table IMU_DATA(token text,scaledaccelx text, scaledaccely text, scaledaccelz text);";
      
      /* Create a transactional object. */
      work W(C);

      /* Execute SQL query */
      W.exec( sql );
      W.commit();

      Json::Value Imu_datas;
      ifstream scene_in(path.c_str());
      if(scene_in.is_open()) scene_in>>Imu_datas;
      cout <<"file open"<<endl;
      std::string temp1;
      std::string temp2;
      std::string temp3;
      std::string temp4;
      cout <<"string"<<endl;
      

      for(int i=0; i<Imu_datas.size(); i++){

	     cout<<"for start"<<endl;

         temp1=std::string((Imu_datas[i]["scaledaccelx"].asString()).c_str());
         temp2=std::string((Imu_datas[i]["scaledaccely"].asString()).c_str());
         temp3=std::string((Imu_datas[i]["scaledaccelz"].asString()).c_str());
         temp4=std::string((Imu_datas[i]["token"].asString()).c_str());

         /* Create a transactional object. */
         work W(C);
	      std::string query_string;
         query_string.append("insert into IMU_DATA values('"); 
	      // *****Set table*****
         query_string.append(temp4);
         query_string.append("','");
         query_string.append(temp1);
         query_string.append("','");
         query_string.append(temp2);
         query_string.append("','");
         query_string.append(temp3);
         query_string.append("');");
         /* Execute SQL query */
         W.exec(query_string);
         W.commit();
	      cout<<"for end"<<endl;
      }
      

      /* Create a transactional object. */
      //work W(C);
      
      /* Execute SQL query */
      //W.exec( sql );
      //W.commit();
      cout << "successfully" << endl;
      C.disconnect ();
   } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
      //return 1;
   }

   //return 0;

}

void ImuStoringThread::stop(){
    stop_flag = true;
}