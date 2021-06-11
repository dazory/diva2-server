#include "CanStoringThread.h"

using namespace std;

CanStoringThread::CanStoringThread(){}

void CanStoringThread::run(){
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
      string path = "/home/cvlab2/DIVA2/diva2-server/can_data.json";
      //string path = "/home/ubuntu/diva2-server/build/test/storing_raw/gps.json";
      //string path = "/home/ubuntu/diva2-server/build/test/receiver_fromMobile_proto/gps.json";

      /* Create SQL statement */
      sql = "create table CAN_DATA(token text,handleAngle text,turnLight text,vehicleSpeed text, gear text);";
      
      /* Create a transactional object. */
      work W(C);

      /* Execute SQL query */
      W.exec( sql );
      W.commit();

      Json::Value Can_datas;
      ifstream scene_in(path.c_str());
      if(scene_in.is_open()) scene_in>>Can_datas;
      cout <<"file open"<<endl;
      std::string temp1;
      std::string temp2;
      std::string temp3;
      std::string temp4;
      std::string temp5;
      cout <<"string"<<endl;
      

      for(int i=0; i<Can_datas.size(); i++){
      // for (ValueConstIterator it = Gps_datas.begin(); it != Gps_datas.end(); ++it)
      //   {
	     cout<<"for start"<<endl;

         temp1=std::string((Can_datas[i]["handleAngle"].asString()).c_str());
         temp2=std::string((Can_datas[i]["turnLight"].asString()).c_str());
         temp3=std::string((Can_datas[i]["vehicleSpeed"].asString()).c_str());
         temp4=std::string((Can_datas[i]["gear"].asString()).c_str());
         temp5=std::string((Can_datas[i]["token"].asString()).c_str());


         /* Create a transactional object. */
         work W(C);
	      std::string query_string;
         query_string.append("insert into CAN_DATA values('"); 
	      // *****Set table*****
         query_string.append(temp5);
         query_string.append("','");
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

void CanStoringThread::stop(){
    stop_flag = true;
}
