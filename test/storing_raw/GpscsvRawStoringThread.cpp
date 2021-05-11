#include "GpsRawStoringThread.h"

using namespace std;

GpsRawStoringThread::GpsRawStoringThread(){}

void GpsRawStoringThread::run(){
    char * sql;
   
    
   try {
      connection C("dbname = ubuntu user = ubuntu password = 1234 \
      hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         //return 1;
      }
      string path = "/home/kayeon/diva2-server/test/storing_raw/gps.csv";
      
      /* Create SQL statement */
      sql = "create table GPS_RAW_DATA(gpgga text,latitude text,isNorth text, longitude text, isEast text, gpsQuality text, numberOfSatellitesInUse text);";
      
      /* Create a transactional object. */
      work W(C);

      /* Execute SQL query */
      W.exec( sql );
      W.commit();

      ifstream in(path);
      cout<<"open csv"<<endl;
      /* csv parsing */

      string line, field;

      vector< vector<string> > array;  // the 2D array
      vector<string> v;                // array of values for one line only

      while ( getline(in,line) )    // get next line in file
      {
         v.clear();
         stringstream ss(line);

         while (getline(ss,field,','))  // break line into comma delimitted fields
         {
               v.push_back(field);  // add each field to the 1D array
         }

         array.push_back(v);  // add the 1D array to the 2D array
      }
      
            std::string temp1;
            std::string temp2;
            std::string temp3;
            std::string temp4;
            std::string temp5;
            std::string temp6;
            std::string temp7;
            cout<<"array "<<endl;

      for (size_t i=0; i<array.size(); ++i)
      {
               
               cout<<"for start1"<<endl;

               temp1=array[i][0];
               temp2=array[i][1];
               temp3=array[i][2];
               temp4=array[i][3];
               temp5=array[i][4];
               temp6=array[i][5];
               temp7=array[i][6];

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

void GpsRawStoringThread::stop(){
    stop_flag = true;
}