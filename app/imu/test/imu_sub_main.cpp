//#include "../idl_gen/imu.h"
//#include "../idl_gen/imuPlugin.h"
//#include "../idl_gen/imuSupport.h"

//#include "dds_wrapper/node.h"

#include <thread>
#include <iostream>
#include <unistd.h>

#include "../../pps_public/topic_imu_app.h"
#include "../../pps_public/app_pps_protocal.h"
#include "../../pps_public/ppscontrol.h"

extern "C"{
	int32_t appLogGlobalTimeInit();
	uint64_t appLogGetGlobalTimeInUsec();
}

static DESY::ppscontrol  *m_ppsctrl;
static DESY::PPS_CFG_STRU g_ppscfg[] = {
    TopicImuApp::cfg(1,0),
};

static void message_callback(int topicid,int cmdid,int size,char *pdata);

int main() {
  
    m_ppsctrl = DESY::ppscontrol::Instance(g_ppscfg,sizeof(g_ppscfg)/sizeof(g_ppscfg[0]));
    DESY::ppscontrol::Instance()->registerCallback(message_callback);

    appLogGlobalTimeInit();

  for (;;) {
    pause();
  }
}

void message_callback(int topicid, int cmdid, int size, char *pdata) {
    printf("rec imuData Msg\n");
    if(topicid == TOPICID_IMU_APP)
    {
        if (cmdid == CMDID_IMU_DATA_APP)
        {
          DesayInterface_pps_IMU_Data_APP*sample; 
          sample = (DesayInterface_pps_IMU_Data_APP*)pdata;
          
          printf("MCU3RTimeus %llu\n",sample->MCU3RTimeus);
          printf("MCU3STimeus %llu\n",sample->MCU3STimeus);
          printf("MCUSocTimeus %llu\n",sample->MCUSocTimeus);
          printf("timestamp %llu\n",sample->timestamp);
          uint64_t apptime = appLogGetGlobalTimeInUsec();
          printf("APPTime %lu\n",apptime);

          printf("Wx:%f\n", sample->Wx);
          printf("Wy:%f\n", sample->Wy);
          printf("Wz:%f\n", sample->Wz);

          printf("Ax:%f\n", sample->Ax);
          printf("Ay:%f\n", sample->Ay);
          printf("Az:%f\n", sample->Az);
          printf("Alrx:%f\n", sample->Alrx);
          printf("Alry:%f\n", sample->Alry);                             
          printf("Alrz:%f\n", sample->Alrz);
        }
    }
}



