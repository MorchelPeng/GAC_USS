#ifndef TOPIC_IMU_APP_H
#define TOPIC_IMU_APP_H

#include "ppscontrol.h"
#include "app_pps_protocal.h"

class TopicImuApp
{
public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub)
    {
        DESY::PPS_CFG_STRU cfg={TOPICID_IMU_APP,"imu_data_app",16,issub,ispub,15,300};
        return cfg;
    }
};

typedef enum
{
    CMDID_IMU_DATA_APP	= 0, //DesayInterface_pps_IMU_Data_APP
    CMDID_IMU_DATA_APP_MAX
} CMDID_IN_IMU_DATA_APP_ENUM;

 class DesayInterface_pps_IMU_Data_APP
 {
 public:
     DEY_UnsignedLongLong MCU3RTimeus;// MCU3_0收到的时间
     DEY_UnsignedLongLong MCU3STimeus;// MCU3_0发送的时间
     DEY_UnsignedLongLong MCUSocTimeus;//A72收到的时间
     DEY_UnsignedLongLong timestamp;

      DEY_Float Wx;
      DEY_Float Wy;
      DEY_Float Wz;

      DEY_Float Ax;
      DEY_Float Ay;
      DEY_Float Az;

      DEY_Float Alrx;
      DEY_Float Alry;
      DEY_Float Alrz;

      DEY_Float Temp1;
      DEY_Float Temp2;
 };

#endif
