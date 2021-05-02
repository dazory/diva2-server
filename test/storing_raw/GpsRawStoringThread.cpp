#include "GpsRawStoringThread.h"

using namespace std;

GpsRawStoringThread::GpsRawStoringThread(){}

void GpsRawStoringThread::run(){
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
      string path = "/home/cvlab2/DIVA2/diva2-server/build/test/receiver_fromMobile_proto/gps.json";
      //string path = "/home/ubuntu/diva2-server/build/test/storing_raw/gps.json";
      //string path = "/home/ubuntu/diva2-server/build/test/receiver_fromMobile_proto/gps.json";

      /* Create SQL statement */
      sql = "create table GPS_RAW_DATA(gpgga text,latitude text,isNorth text, longitude text, isEast text, gpsQuality text, numberOfSatellitesInUse text, horizontalDilutionOfPrecision text, antennaAltitudeMeters text, geoidalSeparationMeters text);";
      
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
      std::string temp5;
      std::string temp6;
      std::string temp7;
      std::string temp8;
      std::string temp9;
      std::string temp10;
      cout <<"string"<<endl;
      

      for(int i=0; i<Gps_datas.size(); i++){
      // for (ValueConstIterator it = Gps_datas.begin(); it != Gps_datas.end(); ++it)
      //   {
	     cout<<"for start"<<endl;
      //       temp1=std::string((*it)["gpgga"].asString()).c_str());
      //       temp2=std::string((*it)["latitude"].asString()).c_str());
      //       temp3=std::string((*it)["isNorth"].asString()).c_str());
      //       temp4=std::string((*it)["longitude"].asString()).c_str());
      //       temp5=std::string((*it)["isEast"].asString()).c_str());
      //       temp6=std::string((*it)["gpsQuality"].asString()).c_str());
      //       temp7=std::string((*it)["numberOfSatellitesInUse"].asString()).c_str());
      //       temp8=std::string((*it)["horizontalDilutionOfPrecision"].asString()).c_str());
      //       temp9=std::string((*it)["antennaAltitudeMeters"].asString()).c_str());
      //       temp10=std::string((*it)["geoidalSeparationMeters"].asString()).c_str());

         temp1=std::string((Gps_datas[i]["gpgga"].asString()).c_str());
         temp2=std::string((Gps_datas[i]["latitude"].asString()).c_str());
         temp3=std::string((Gps_datas[i]["isNorth"].asString()).c_str());
         temp4=std::string((Gps_datas[i]["longitude"].asString()).c_str());
         temp5=std::string((Gps_datas[i]["isEast"].asString()).c_str());
         temp6=std::string((Gps_datas[i]["gpsQuality"].asString()).c_str());
         temp7=std::string((Gps_datas[i]["NumberOfSatellitesInUse"].asString()).c_str());
         temp8=std::string((Gps_datas[i]["HorizontalDilutionOfPrecision"].asString()).c_str());
         temp9=std::string((Gps_datas[i]["AntennaAltitudeMeters"].asString()).c_str());
         temp10=std::string((Gps_datas[i]["GeoidalSeparationMeters"].asString()).c_str());

         /* Create a transactional object. */
         work W(C);
	      std::string query_string;
         query_string.append("insert into GPS_RAW_DATA values('"); 
	      // *****Set table*****
         query_string.append(temp1);
         query_string.append("','");
         query_string.append(temp2);
         query_string.append("','");
         query_string.append(temp3);
         query_string.append("','");
         query_string.append(temp4);
         query_string.append("','");
         query_string.append(temp5);
         query_string.append("','");
         query_string.append(temp6);
         query_string.append("','");
         query_string.append(temp7);
         query_string.append("','");
         query_string.append(temp8);
         query_string.append("','");
         query_string.append(temp9);
         query_string.append("','");
         query_string.append(temp10);
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

void GpsRawStoringThread::stop(){
    stop_flag = true;
}