#include <thread>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

extern "C"{
    int32_t appLogGlobalTimeInit();
    uint64_t appLogGetGlobalTimeInUsec();
}


static DESY::ppscontrol  *m_ppsctrl;
static DESY::PPS_CFG_STRU g_ppscfg[] = {
    topicid_motovis_apa_fusion::cfg_subscribe,
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
    // if(topicid == TOPICID_GAC_CAN_RX && cmdid == CMDID_CAN_SIGNAL_RX_SLOW)
    // {
    //     DesayInterface_pps_canSignalRx_Slow *sample;
    //     sample = (DesayInterface_pps_canSignalRx_Slow*)pdata;
    //     printf("MCU1Timeus %lld\r\n", sample->MCU1Timeus);

    //     printf("MCU3RTimeus %lld\r\n", sample->MCU3RTimeus);
    //     printf("MCU3STimeus %lld\r\n", sample->MCU3STimeus);
    //     printf("MCUSocTimeus %lld\r\n", sample->MCUSocTimeus);

    //    uint64_t apptime=appLogGetGlobalTimeInUsec();
    //     printf("APPTime %lld\r\n",apptime);
    //     printf("TEL_FAPAVideoUpIP %d\r\n",sample->TEL_FAPAVideoUpIP);
    //     printf("ACU_SVM_Button %d\r\n",sample->ACU_SVM_Button);
    //     printf("ACU_APA_Button %d\r\n",sample->ACU_APA_Button);
    //     printf("ACU_ORVMOperationReq %d\r\n",sample->ACU_ORVMOperationReq);
    //     printf("ACU_AltitudeInteger %d\r\n",sample->ACU_AltitudeInteger);
    //     printf("ACU_AzimuthInfo %d\r\n",sample->ACU_AzimuthInfo);
    //     printf("ACU_GPSSignalSt %d\r\n",sample->ACU_GPSSignalSt);
    //     printf("ACU_AltitudeDecimal %d\r\n",sample->ACU_AltitudeDecimal)	;
    //     printf("DMS_FaceIDDeleteResult %d\r\n",sample->DMS_FaceIDDeleteResult)	;
    //     printf("DMS_DrvrDetSts %d\r\n",sample->DMS_DrvrDetSts);
    //     printf("TEL_Time_Sec %d\r\n",sample->TEL_Time_Sec);
    //     printf("TEL_TimeVD %d\r\n",sample->TEL_TimeVD);
    //     printf("TEL_Time_Min %d\r\n",sample->TEL_Time_Min);
    //     printf("TEL_Time_Day %d\r\n",sample->TEL_Time_Day);
    //     printf("TEL_Time_Hour %d\r\n",sample->TEL_Time_Hour);
    //     printf("TEL_Time_Month %d\r\n",sample->TEL_Time_Month);
    //     printf("TEL_Time_Year %d\r\n",sample->TEL_Time_Year);
    //     printf("ACU_ThemeType %d\r\n",sample->ACU_ThemeType);
    //     printf("ACU_Time_Sec %d\r\n",sample->ACU_Time_Sec);
    //     printf("ACU_LanguageTypeSet %d\r\n",sample->ACU_LanguageTypeSet);
    //     printf("ACU_Time_Min %d\r\n",sample->ACU_Time_Min);
    //     printf("ACU_Time_Day %d\r\n",sample->ACU_Time_Day);
    //     printf("ACU_Time_Hour %d\r\n",sample->ACU_Time_Hour);
    //     printf("ACU_Time_Month %d\r\n",sample->ACU_Time_Month);
    //     printf("ACU_Time_Year %d\r\n",sample->ACU_Time_Year);
    //     printf("TEL_Latitude %d\r\n",sample->TEL_Latitude);
    //     printf("TEL_Longitude %d\r\n",sample->TEL_Longitude);
    //     printf("PEPS_SATOQuitReason %d\r\n",sample->PEPS_SATOQuitReason);
    //     printf("PEPS_WALQuitReason %d\r\n",sample->PEPS_WALQuitReason);
    //     printf("PEPS_APUQuitReason %d\r\n",sample->PEPS_APUQuitReason);
    //     printf("PEPS_WELQuitReason %d\r\n",sample->PEPS_WELQuitReason);
    //     printf("ACU_IFC_NaviSt %d\r\n",sample->ACU_IFC_NaviSt);
    //     printf("ACU_IFC_RoadType %d\r\n",sample->ACU_IFC_RoadType);
    //     printf("RLS_RainfallLevel %d\r\n",sample->RLS_RainfallLevel);
    //     printf("PCTime_0 %d\r\n",sample->PCTime_0);
    //     printf("PCTime_1 %d\r\n",sample->PCTime_1);
    //     printf("PCTime_2 %d\r\n",sample->PCTime_2);
    //     printf("PCTime_3 %d\r\n",sample->PCTime_3);
    //     printf("PCTime_4 %d\r\n",sample->PCTime_4);
    //     printf("PCTime_5 %d\r\n",sample->PCTime_5);
    //     printf("PCTime_6 %d\r\n",sample->PCTime_6);

    // }
}





