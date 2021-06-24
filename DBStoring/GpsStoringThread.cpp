#include "GpsStoringThread.h"

using namespace std;

GpsStoringThread::GpsStoringThread(){}

void GpsStoringThread::run(){
    char * sql;
    time_t system_time;
    struct tm* systime;
    system_time = time(NULL);
    systime = localtime(&system_time);

    string tm_year = to_string(systime->tm_year + 1900);
    string tm_month = to_string(systime->tm_mon+1);
    string tm_date = to_string(systime->tm_mday);
    if(tm_date.size() == 1){
        tm_date = "0"+tm_date;
    }

    string timestamp;
    timestamp = tm_year + tm_month + tm_date;
     
   try {
      connection C("dbname = diva2db user = diva2 password = 1234 \
      hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         //return 1;
      }

      string path = "/home/cvlab2/DIVA2/diva2-server/DIVA2_DATA/"+timestamp+"_0/JSON/gps_data.json";
      // string path = "/home/cvlab2/DIVA2/diva2-server/DIVA2data/"+timestamp+"/JSON/cam_data.json";
      //string path = "/home/ubuntu/diva2-server/build/test/storing_raw/gps.json";
      //string path = "/home/ubuntu/diva2-server/build/test/receiver_fromMobile_proto/gps.json";

      /* Create SQL statement */
      sql = "create table GPS_DATA(token text primary key references frame (frame_token),latitude text,longitude text, HorizontalDilutionOfPrecision text);";
      
      /* Create a transactional object. */
      work W(C);

      /* Execute SQL query */
      W.exec( sql );
      W.commit();

      Json::Value Gps_datas;
      ifstream scene_in(path.c_str());
      if(scene_in.is_open()) scene_in>>Gps_datas;
      cout <<"file open"<<endl;
      std::string temp1;
      std::string temp2;
      std::string temp3;
      std::string temp4;
      cout <<"string"<<endl;
      

      for(int i=0; i<Gps_datas.size(); i++){

	     cout<<"for start"<<endl;
         temp1=std::string((Gps_datas[i]["token"].asString()).c_str());
         temp2=std::string((Gps_datas[i]["latitude"].asString()).c_str());
         temp3=std::string((Gps_datas[i]["longitude"].asString()).c_str());
         temp4=std::string((Gps_datas[i]["HorizontalDilutionOfPrecision"].asString()).c_str());

         /* Create a transactional object. */
         work W(C);
	      std::string query_string;
         query_string.append("explain analyze insert into GPS_DATA values('"); 
	      // *****Set table*****
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
      cout << "[DBStoring] gps successfully" << endl;
      C.disconnect ();
   
   } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
      //return 1;
   }

   //return 0;

}

void GpsStoringThread::stop(){
    stop_flag = true;
}