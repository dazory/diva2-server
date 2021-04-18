#pragma once
#include "IMU_Sensing.h"

IMU_Sensing::IMU_Sensing()
{
      mImuPacket = ImuPacket();
}
mscl::InertialNode IMU_Sensing::getMsclNode(const char *devicename, mscl::uint32 baudrate)
{
      /*
      : Make sure to replace ${devicename} and ${baudrate} with your own port settings.
      */

      //create the connection object with port and baud rate
      mscl::Connection connection = mscl::Connection::Serial(devicename, baudrate);

      //create the InertialNode, passing in the connection
      mscl::InertialNode node = mscl::InertialNode(connection);
      return node;
}

//sensors::Imu pIMU 파라미터 추가
sensors::Imu IMU_Sensing::read_IMUPacket(int enumIMU, mscl::MipDataPoint dataPoint)
{
      sensors::Imu pIMU;
      switch (enumIMU)
      {
      case IMU_ACCELX:
      {
            pIMU.set_scaledaccelx(dataPoint.as_float());
            printf("IMU_ACCELX\n");
            break;
      }
      case IMU_ACCELY:
      {
            pIMU.set_scaledaccely(dataPoint.as_float());
            printf("IMU_ACCELY\n");
            break;
      }
      case IMU_ACCELZ:
      {
            pIMU.set_scaledaccelz(dataPoint.as_float());
            printf("IMU_ACCELZ\n");
            break;
      }
      case IMU_GYROX:
      {
            pIMU.set_scaledgyrox(dataPoint.as_float());
            printf("IMU_GYROX\n");
            break;
      }
      case IMU_GYROY:
      {
            pIMU.set_scaledgyroy(dataPoint.as_float());
            printf("IMU_GYROY\n");
            break;
      }
      case IMU_GYROZ:
      {
            pIMU.set_scaledgyroz(dataPoint.as_float());
            printf("IMU_GYROZ\n");
            break;
      }
      case IMU_MAGX:
      {
            pIMU.set_scaledmagx(dataPoint.as_float());
            printf("IMU_MAGX\n");
            break;
      }
      case IMU_MAGY:
      {
            pIMU.set_scaledmagy(dataPoint.as_float());
            printf("IMU_MAGY\n");
            break;
      }
      case IMU_MAGZ:
      {
            pIMU.set_scaledmagz(dataPoint.as_float());
            printf("IMU_MAGZ\n");
            break;
      }

      case IMU_ESTROLL:
      {
            pIMU.set_estroll(dataPoint.as_float());
            printf("IMU_ESTROLL\n");
            break;
      }
      case IMU_ESTPITCH:
      {
            pIMU.set_estpitch(dataPoint.as_float());
            printf("IMU_ESTPITCH\n");
            break;
      }
      case IMU_ESTYAW:
      {
            pIMU.set_estyaw(dataPoint.as_float());
            printf("IMU_ESTYAW\n");
            break;
      }

      case IMU_ESTROLL_UNCERT:
      {
            pIMU.set_estrolluncert(dataPoint.as_float());
            printf("IMU_ESTROLL_UNCERT\n");
            break;
      }
      case IMU_ESTPITCH_UNCERT:
      {
            pIMU.set_estpitchuncert(dataPoint.as_float());
            printf("IMU_ESTPITCH_UNCERT\n");
            break;
      }
      case IMU_ESTYAW_UNCERT:
      {
            pIMU.set_estyawuncert(dataPoint.as_float());
            printf("IMU_ESTYAW_UNCERT\n");
            break;
      }

      default:
      {
            printf("\n");
            break;
      }
      }
      return pIMU;
}

void IMU_Sensing::Display_protoIMU(sensors::Imu &pIMU)
{
      //~~~~~~ json과 비슷. 변수 : value ~~~~~~~~~~~
      // 그런데 timestamp가 알아보기 힘들어짐
      // string strTxt;
      // google::protobuf::TextFormat::PrintToString(pIMU, &strTxt);
      // cout<<strTxt<<endl;

      ////~~~~~~ json 형식으로 출력 "Key" : Value ~~~~~~
      string json_string;
      google::protobuf::util::JsonPrintOptions options;
      options.add_whitespace = true;
      options.always_print_primitive_fields = true;
      options.preserve_proto_field_names = true;
      google::protobuf::util::MessageToJsonString(pIMU, &json_string, options);
      cout << json_string << endl;
}

// void IMU_Sensing::Display(){
//       printf("Accel (X,Y,Z) = (%.2f, %.2f, %.2f)\n",mImuPacket.scaledAccelX,mImuPacket.scaledAccelY,mImuPacket.scaledAccelZ );
//       printf("Gyro (X,Y,Z) = (%.2f, %.2f, %.2f)\n",mImuPacket.scaledGyroX,mImuPacket.scaledGyroY,mImuPacket.scaledGyroZ );
//       printf("Mag (X,Y,Z) = (%.2f, %.2f, %.2f)\n",mImuPacket.scaledMagX,mImuPacket.scaledMagY,mImuPacket.scaledMagZ );
//       printf("est (Roll,Pitch,Yaw) = (%.2f, %.2f, %.2f)\n",mImuPacket.estRoll,mImuPacket.estPitch,mImuPacket.estYaw );
//       printf("estUncert (Roll,Pitch,Yaw) = (%.2f, %.2f, %.2f)\n",mImuPacket.estRollUncert,mImuPacket.estPitchUncert,mImuPacket.estYawUncert );
// }

size_t IMU_Sensing::getImuPacketSize()
{
      return sizeof(mImuPacket);
}
size_t IMU_Sensing::getImuPacketsSize()
{
      return sizeof(mImuPackets);
}

ImuPacket IMU_Sensing::getImuPacket()
{
      return mImuPacket;
}