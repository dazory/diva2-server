#include "CamStoringThread.h"

using namespace std;

CamStoringThread::CamStoringThread(){}

void CamStoringThread::run(){
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
      }
      string path = "/home/cvlab2/DIVA2/diva2-server/DIVA2data/"+timestamp+"_0/JSON/cam_data.json";

      /* Create SQL statement */
      sql = "create table CAM_DATA(token text, fileformat text, filename text);";
      
      /* Create a transactional object. */
      work W(C);

      /* Execute SQL query */
      W.exec( sql );
      W.commit();

      Json::Value Cam_datas;
      ifstream scene_in(path.c_str());
      if(scene_in.is_open()) scene_in>>Cam_datas;
      cout <<"file open"<<endl;
      std::string temp1;
      std::string temp2;
      std::string temp3;
      cout <<"string"<<endl;
      

      for(int i=0; i<Cam_datas.size(); i++){
	     cout<<"for start"<<endl;
         temp1=std::string((Cam_datas[i]["token"].asString()).c_str());
         temp2=std::string((Cam_datas[i]["fileformat"].asString()).c_str());
         temp3=std::string((Cam_datas[i]["filename"].asString()).c_str());

         /* Create a transactional object. */
         work W(C);
	      std::string query_string;
         query_string.append("insert into CAM_DATA values('"); 
            
         // *****Set table*****
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
      
      cout << "successfully" << endl;
      C.disconnect ();
   } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
   }

}

void CamStoringThread::stop(){
    stop_flag = true;
}