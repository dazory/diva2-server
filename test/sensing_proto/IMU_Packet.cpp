//multiple 오류 -> service에서 IMUpacket 헤더랑 분리 -> service에 CMakeLists없어서 정의를 못찾음...ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ지저분 하지만 일단 옮김
#include "../service/IMU_Packet.h"


ImuPacket::ImuPacket(){
    time = NULL;
    scaledAccelX=0;  scaledAccelY=0; scaledAccelZ=0;
    scaledGyroX=0; scaledGyroY=0; scaledGyroZ=0;
    scaledMagX=0; scaledMagY=0; scaledMagZ=0;
    estRoll=0; estPitch=0; estYaw=0;
    estRollUncert=NULL; estPitchUncert=NULL; estYawUncert=NULL;
}

void Init(){
    ImuMap["scaledAccelX"] = IMU_ACCELX;
    ImuMap["scaledAccelY"] = IMU_ACCELY;
    ImuMap["scaledAccelZ"] = IMU_ACCELZ;
    ImuMap["scaledGyroX"] = IMU_GYROX;
    ImuMap["scaledGyroY"] = IMU_GYROY;
    ImuMap["scaledGyroZ"] = IMU_GYROZ;
    ImuMap["scaledMagX"] = IMU_MAGX;
    ImuMap["scaledMagY"] = IMU_MAGY;
    ImuMap["scaledMagZ"] = IMU_MAGZ;

    ImuMap["estRoll"] = IMU_ESTROLL;
    ImuMap["estPitch"] = IMU_ESTPITCH;
    ImuMap["estYaw"] = IMU_ESTYAW;

    ImuMap["estRollUncert"] = IMU_ESTROLL_UNCERT;
    ImuMap["estPitchUncert"] = IMU_ESTPITCH_UNCERT;
    ImuMap["estYawUncert"] = IMU_ESTYAW_UNCERT;

    ImuMap[""] = IMU_EXCEPTION;
}

void ImuPacket::display(){
    printf("Accel (X,Y,Z) = (%.2f, %.2f, %.2f)\n",scaledAccelX,scaledAccelY,scaledAccelZ );
    printf("Gyro (X,Y,Z) = (%.2f, %.2f, %.2f)\n",scaledGyroX,scaledGyroY,scaledGyroZ );
    printf("Mag (X,Y,Z) = (%.2f, %.2f, %.2f)\n",scaledMagX,scaledMagY,scaledMagZ );
    printf("est (Roll,Pitch,Yaw) = (%.2f, %.2f, %.2f)\n",estRoll,estPitch,estYaw );
    printf("estUncert (Roll,Pitch,Yaw) = (%.2f, %.2f, %.2f)\n",estRollUncert,estPitchUncert,estYawUncert );
    // printf("Accel (X,Y,Z) = (%.2f, %.2f, %.2f)\n",mImuPacket.scaledAccelX,mImuPacket.scaledAccelY,mImuPacket.scaledAccelZ );
    // printf("Gyro (X,Y,Z) = (%.2f, %.2f, %.2f)\n",mImuPacket.scaledGyroX,mImuPacket.scaledGyroY,mImuPacket.scaledGyroZ );
    // printf("Mag (X,Y,Z) = (%.2f, %.2f, %.2f)\n",mImuPacket.scaledMagX,mImuPacket.scaledMagY,mImuPacket.scaledMagZ );
    // printf("est (Roll,Pitch,Yaw) = (%.2f, %.2f, %.2f)\n",mImuPacket.estRoll,mImuPacket.estPitch,mImuPacket.estYaw );
    // printf("estUncert (Roll,Pitch,Yaw) = (%.2f, %.2f, %.2f)\n",mImuPacket.estRollUncert,mImuPacket.estPitchUncert,mImuPacket.estYawUncert );       
}