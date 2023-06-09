#include "../../pps_public/app_pps_protocal.h"
#include "../../pps_public/ppscontrol.h"
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
    //topicid_motovis_apa_fusion::cfg_subscribe
};

static void message_callback(int topicid,int cmdid,int size,char *pdata);

int main() {

    m_ppsctrl = DESY::ppscontrol::Instance(g_ppscfg,sizeof(g_ppscfg)/sizeof(g_ppscfg[0]));
    DESY::ppscontrol::Instance()->registerCallback(message_callback);
    // printf("Event:%lu\t 20ms:%lu\t 100ms%lu\t 500ms:%lu\n",
    //        sizeof(DesayInterface_pps_IdtCanSignalRxRouteEvent),
    //        //sizeof(DesayInterface_pps_IdtCanSignalRxRoute10ms),
    //        sizeof(DesayInterface_pps_IdtCanSignalRxRoute20ms),
    //        sizeof(DesayInterface_pps_IdtCanSignalRxRoute100ms),
    //        sizeof(DesayInterface_pps_IdtCanSignalRxRoute500ms));

      appLogGlobalTimeInit();

  for (;;) {
    pause();
  }
}

void message_callback(int topicid, int cmdid, int size, char *pdata) 
{
    // if(topicid == TOPICID_GAC_CAN_RX && cmdid == CMDID_CAN_SIGNAL_RX_EVENT)
    // {
    //    DesayInterface_pps_IdtCanSignalRxRouteEvent *sample ;
    //    sample= (DesayInterface_pps_IdtCanSignalRxRouteEvent*)pdata;
    //    printf("WarnTone_ButtonPress:%d\n",sample->WarnTone_ButtonPress);
    //    printf("ScreenTouchSt:%d\n",sample->ScreenTouchSt);
    //    printf("CurrentSceenSt:%d\n",sample->CurrentSceenSt);
    //    printf("ScreenCoordY:%d\n",sample->ScreenCoordY);
    //    printf("ScreenCoordX:%d\n",sample->ScreenCoordX);
    //    printf("SVM_VRSwitch:%d\n",sample->SVM_VRSwitch);
    //    printf("SVM_ButtonPress:%d\n",sample->SVM_ButtonPress);
    // }
//     else if(topicid == TOPICID_GAC_CAN_RX && cmdid == CMDID_CAN_SIGNAL_RX_10MS)
//     {
//         DesayInterface_pps_IdtCanSignalRxRoute10ms *sample ;
//         sample= (DesayInterface_pps_IdtCanSignalRxRoute10ms*)pdata;
//        printf("MCU1RTimeus:%llu\r\n",sample->MCU1RTimeus);
//        printf("MCU1STimeus:%llu\r\n",sample->MCU1STimeus);
//        printf("MCU3RTimeus:%llu\r\n",sample->MCU3RTimeus);
//        printf("MCU3STimeus:%llu\r\n",sample->MCU3STimeus);
//        printf("MCUSocTimeus:%llu\r\n",sample->MCUSocTimeus);
//        printf("BCS_ABSActiveSt:%d\r\n",sample->BCS_ABSActiveSt);
//        printf("BCS_ABSFaultSt:%d\r\n",sample->BCS_ABSFaultSt);
//        printf("BCS_EBDFaultSt:%d\r\n",sample->BCS_EBDFaultSt);
//        printf("BCS_EBDActiveSt:%d\r\n",sample->BCS_EBDActiveSt);
//        printf("BCS_TCSFaultSt:%d\r\n",sample->BCS_TCSFaultSt);
//        printf("BCS_TCSActiveSt:%d\r\n",sample->BCS_TCSActiveSt);
//        printf("BCS_VDCFaultSt:%d\r\n",sample->BCS_VDCFaultSt);
//        printf("BCS_VehSpdVD:%d\r\n",sample->BCS_VehSpdVD);
//        printf("BCS_VehSpd:%d\r\n",sample->BCS_VehSpd);
//        printf("BCS_VDCActiveSt:%d\r\n",sample->BCS_VDCActiveSt);
//        printf("SAS_SteeringAngleVD:%d\r\n",sample->SAS_SteeringAngleVD);
//        printf("SAS_CalibratedSt:%d\r\n",sample->SAS_CalibratedSt);
//        printf("SAS_SteeringAngle:%d\r\n",sample->SAS_SteeringAngle);
//        printf("TCU_GearForDisp:%d\r\n",sample->TCU_GearForDisp);
//        printf("TCU_CurrentGearSt:%d\r\n",sample->TCU_CurrentGearSt);
//        printf("TCU_CurrentGearStVD:%d\r\n",sample->TCU_CurrentGearStVD);
//        printf("EMS_GasPedalActPst:%d\r\n",sample->EMS_GasPedalActPst);
//        printf("EMS_GasPedalActPstVD:%d\r\n",sample->EMS_GasPedalActPstVD);
//        printf("EMS_BrakePedalStVD:%d\r\n",sample->EMS_BrakePedalStVD);
//        printf("EMS_BrakePedalSt:%d\r\n",sample->EMS_BrakePedalSt);
//        printf("EMS_EngSt:%d\r\n",sample->EMS_EngSt);
//        printf("EMS_GasPedalActPstforMRRVD:%d\r\n",sample->EMS_GasPedalActPstforMRRVD);
//        printf("EMS_GasPedalActPstforMRR:%d\r\n",sample->EMS_GasPedalActPstforMRR);
//        printf("EMS_MaxEngTorqNorm:%d\r\n",sample->EMS_MaxEngTorqNorm);
//        printf("EMS_ClutchTorqDriverReqVD:%d\r\n",sample->EMS_ClutchTorqDriverReqVD);
//        printf("EMS_ClutchTorqVD:%d\r\n",sample->EMS_ClutchTorqVD);
//        printf("EMS_EngFrictionTorqVD:%d\r\n",sample->EMS_EngFrictionTorqVD);
//        printf("EMS_ClutchTorq:%d\r\n",sample->EMS_ClutchTorq);
//        printf("EMS_ClutchTorqDriverReq:%d\r\n",sample->EMS_ClutchTorqDriverReq);
//        printf("EMS_EngFrictionTorq:%d\r\n",sample->EMS_EngFrictionTorq);
//        printf("EMS_MinClutchTorq:%d\r\n",sample->EMS_MinClutchTorq);
//        printf("EMS_MaxClutchTorq:%d\r\n",sample->EMS_MaxClutchTorq);
//        printf("EMS_MaxClutchTorqVD:%d\r\n",sample->EMS_MaxClutchTorqVD);
//        printf("EMS_MinClutchTorqVD:%d\r\n",sample->EMS_MinClutchTorqVD);
//     }
    // else if(topicid == TOPICID_GAC_CAN_RX && cmdid == CMDID_CAN_SIGNAL_RX_20MS)
    // {
    //    DesayInterface_pps_IdtCanSignalRxRoute20ms *sample ;
    //    sample= (DesayInterface_pps_IdtCanSignalRxRoute20ms*)pdata;
    //    printf("VehSpdVD:%d\n", sample->VehSpdVD);
    //    printf("VehSpd:%f\n", sample->VehSpd);
    //    printf("SteeringAngleVD:%d\n", sample->SteeringAngleVD);
    //    printf("SteAngSen_CalibratedSt:%d\n", sample->SteAngSen_CalibratedSt);
    //    printf("SteeringAngle:%f\n", sample->SteeringAngle);
    //    printf("CurrentGearSt:%d\n", sample->CurrentGearSt);
    //    printf("CurrentGearStVD:%d\n", sample->CurrentGearStVD);
    //    printf("FLWheelSpdVD:%d\n", sample->FLWheelSpdVD);
    //    printf("FLWheelRotatedDirection:%d\n", sample->FLWheelRotatedDirection);
    //    printf("FLWheelRotatedDirectionVD:%d\n", sample->FLWheelRotatedDirectionVD);
    //    printf("FLWheelSpd:%f\n", sample->FLWheelSpd);
    //    printf("FRWheelRotatedDirectionVD:%d\n", sample->FRWheelRotatedDirectionVD);
    //    printf("FRWheelRotatedDirection:%d\n", sample->FRWheelRotatedDirection);
    //    printf("FRWheelSpdVD:%d\n", sample->FRWheelSpdVD);
    //    printf("FRWheelSpd:%f\n", sample->FRWheelSpd);
    //    printf("FLWheelRotatedDirectionAPA:%d\n", sample->FLWheelRotatedDirectionAPA);
    //    printf("FRWheelRotatedDirectionAPA:%d\n", sample->FRWheelRotatedDirectionAPA);
    //    printf("PreVDCActiveSt:%d\n", sample->PreVDCActiveSt);
    //    printf("RLWheelSpdVD:%d\n", sample->RLWheelSpdVD);
    //    printf("RLWheelRotatedDirection:%d\n", sample->RLWheelRotatedDirection);
    //    printf("RLWheelRotatedDirectionVD:%d\n", sample->RLWheelRotatedDirectionVD);
    //    printf("RLWheelSpd:%f\n", sample->RLWheelSpd);
    //    printf("RRWheelRotatedDirectionVD:%d\n", sample->RRWheelRotatedDirectionVD);
    //    printf("RRWheelRotatedDirection:%d\n", sample->RRWheelRotatedDirection);
    //    printf("RRWheelSpdVD:%d\n", sample->RRWheelSpdVD);
    //    printf("RRWheelSpd:%f\n", sample->RRWheelSpd);
    //    printf("RLWheelRotatedDirectionAPA:%d\n", sample->RLWheelRotatedDirectionAPA);
    //    printf("RRWheelRotatedDirectionAPA:%d\n", sample->RRWheelRotatedDirectionAPA);
    // }
    // else if(topicid == TOPICID_GAC_CAN_RX && cmdid == CMDID_CAN_SIGNAL_RX_100MS)
    // {
    //    DesayInterface_pps_IdtCanSignalRxRoute100ms *sample ;
    //    sample= (DesayInterface_pps_IdtCanSignalRxRoute100ms*)pdata;
    //    printf("LowBeamSt:%d\n", sample->LowBeamSt);
    //    printf("HighBeamSt:%d\n", sample->HighBeamSt);
    //    printf("VehKeySt:%d\n", sample->VehKeySt);
    //    printf("BonnetAjarSt:%d\n", sample->BonnetAjarSt);
    //    printf("ReverseSwitchSt:%d\n", sample->ReverseSwitchSt);
    //    printf("DriverDoorAjarSt:%d\n", sample->DriverDoorAjarSt);
    //    printf("BrakeLightSwitchSt:%d\n", sample->BrakeLightSwitchSt);
    //    printf("TrunkAjarSt:%d\n", sample->TrunkAjarSt);
    //    printf("PsngrDoorAjarSt:%d\n", sample->PsngrDoorAjarSt);
    //    printf("RLDoorAjarSt:%d\n", sample->RLDoorAjarSt);
    //    printf("RRDoorAjarSt:%d\n", sample->RRDoorAjarSt);
    //    printf("LeftTurnLampSt:%d\n", sample->LeftTurnLampSt);
    //    printf("LeftTurnLampFaultSt:%d\n", sample->LeftTurnLampFaultSt);
    //    printf("RightTurnLampSt:%d\n", sample->RightTurnLampSt);
    //    printf("RightTurnLampFaultSt:%d\n", sample->RightTurnLampFaultSt);
    //    printf("TurnLightSwitchSt:%d\n", sample->TurnLightSwitchSt);
    //    printf("HazardLampSt:%d\n", sample->HazardLampSt);
    //    printf("ReverseLightSt:%d\n", sample->ReverseLightSt);
    //    printf("BrakeLightSt:%d\n", sample->BrakeLightSt);
    //    printf("BrakeLightFaultSt:%d\n", sample->BrakeLightFaultSt);
    // }
    // else if(topicid == TOPICID_GAC_CAN_RX && cmdid == CMDID_CAN_SIGNAL_RX_500MS)
    // {
    //     DesayInterface_pps_IdtCanSignalRxRoute500ms *sample ;
    //     sample= (DesayInterface_pps_IdtCanSignalRxRoute500ms*)pdata;
    //     printf("MCU1RTimeus%lld\r\n", sample->MCU1RTimeus);
    //     printf("MCU1STimeus%lld\r\n", sample->MCU1STimeus);
    //     printf("MCU3RTimeus%lld\r\n", sample->MCU3RTimeus);
    //     printf("MCU3STimeus%lld\r\n", sample->MCU3STimeus);
    //     printf("MCUSocTimeus%lld\r\n", sample->MCUSocTimeus);
    //     printf("ACU_Time_Year%d\r\n", sample->ACU_Time_Year);
    //     printf("ACU_Time_Month%d\r\n", sample->ACU_Time_Month);
    //     printf("ACU_Time_Hour%d\r\n", sample->ACU_Time_Hour);
    //     printf("ACU_Time_Day%d\r\n", sample->ACU_Time_Day);
    //     printf("ACU_Time_Min%d\r\n", sample->ACU_Time_Min);
    //     printf("ACU_LanguageTypeSet%d\r\n", sample->ACU_LanguageTypeSet);
    //     printf("ACU_Time_Sec%d\r\n", sample->ACU_Time_Sec);
    //     printf("ACU_ThemeType%d\r\n", sample->ACU_ThemeType);
    //     printf("RLS_RainfallLevel%d\r\n", sample->RLS_RainfallLevel);
    //     printf("PEPS_WELQuitReason%d\r\n", sample->PEPS_WELQuitReason);
    //     printf("PEPS_APUQuitReason%d\r\n", sample->PEPS_APUQuitReason);
    //     printf("PEPS_WALQuitReason%d\r\n", sample->PEPS_WALQuitReason);
    //     printf("PEPS_SATOQuitReason%d\r\n", sample->PEPS_SATOQuitReason);

    //     //new add 0302
    //     printf("TEL_Longitude:%d\r\n",sample->TEL_Longitude);
    //     printf("TEL_Latitude:%d\r\n",sample->TEL_Latitude);
    //     printf("TEL_NaviPstVD:%d\r\n",sample->TEL_NaviPstVD);
    //     printf("ACU_AUID:%d\r\n",sample->ACU_AUID);
    //     printf("TEL_NetworkMode:%d\r\n",sample->TEL_NetworkMode);
    //     printf("TEL_SignalStrength:%d\r\n",sample->TEL_SignalStrength);
    //     printf("TEL_GPSState:%d\r\n",sample->TEL_GPSState);
    //     printf("TEL_SatelliteNum:%d\r\n",sample->TEL_SatelliteNum);
    // }
}





