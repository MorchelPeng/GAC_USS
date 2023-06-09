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
    topicid_motovis_apa_fusion::cfg_subscribe
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
    // if(topicid == TOPICID_GAC_CAN_RX && cmdid == CMDID_CAN_SIGNAL_RX_FAST)
    // {
    //     DesayInterface_pps_canSignalRx_Fast *sample ;
    //     sample= (DesayInterface_pps_canSignalRx_Fast*)pdata;
    //     printf("MCU1RTimeus %lld\r\n", sample->MCU1RTimeus);
    //     printf("MCU1STimeus %lld\r\n", sample->MCU1STimeus);
    //     printf("MCU3RTimeus %lld\r\n", sample->MCU3RTimeus);
    //     printf("MCU3STimeus %lld\r\n", sample->MCU3STimeus);
    //     printf("MCUSocTimeus %lld\r\n", sample->MCUSocTimeus);
    //     uint64_t apptime=appLogGetGlobalTimeInUsec();
    //     printf("APPTime %lld\r\n",apptime);


    //     printf("TEL_FAPAVideoReqSt %d \r\n", sample->TEL_FAPAVideoReqSt);
    //     printf("TEL_PCS_EventRecordCtrlReq %d \r\n", sample->TEL_PCS_EventRecordCtrlReq);
    //     printf("TEL_PCS_CtrlReq %d \r\n", sample->TEL_PCS_CtrlReq);
    //     printf("ACU_SVM_RightBlindViewReq %d \r\n", sample->ACU_SVM_RightBlindViewReq);
    //     printf("ACU_SVM_LeftBlindViewReq %d \r\n", sample->ACU_SVM_LeftBlindViewReq);
    //     printf("ACU_PCS_ScreenCoordX %d \r\n",        sample->ACU_PCS_ScreenCoordX);
    //     printf("ACU_PCS_ScreenCoordY %d \r\n",        sample->ACU_PCS_ScreenCoordY);
    //     printf("ACU_PCS_ScreenTouchSt %d \r\n",        sample->ACU_PCS_ScreenTouchSt);
    //     printf("ACU_PCS_ER_QuitConfirm %d \r\n",        sample->ACU_PCS_ER_QuitConfirm);
    //     printf("ACU_PCS_ER_EnterCmd %d \r\n",        sample->ACU_PCS_ER_EnterCmd);
    //     printf("ACU_ER_FuncCfg %d \r\n",        sample->ACU_ER_FuncCfg);
    //     printf("ACU_PCS_AdjParkPosCmd %d \r\n",        sample->ACU_PCS_AdjParkPosCmd);
    //     printf("ACU_PCS_SVM_PGSReturnCmd %d \r\n",        sample->ACU_PCS_SVM_PGSReturnCmd);
    //     printf("ACU_PCS_SVM_SoundReminderCmd %d \r\n",        sample->ACU_PCS_SVM_SoundReminderCmd);
    //     printf("ACU_PCS_SVM_ViewModeCmd %d \r\n",        sample->ACU_PCS_SVM_ViewModeCmd);
    //     printf("ACU_PCS_SVM_MODCmd %d \r\n",        sample->ACU_PCS_SVM_MODCmd);
    //     printf("ACU_PCS_SVM_PGSCmd %d \r\n",        sample->ACU_PCS_SVM_PGSCmd);
    //     printf("ACU_PCS_SVM_SingleViewCmd %d \r\n",        sample->ACU_PCS_SVM_SingleViewCmd);
    //     printf("ACU_PCS_SVM_FunctionCmd %d \r\n",        sample->ACU_PCS_SVM_FunctionCmd);
    //     printf("ACU_PAS_ButtonPress %d \r\n",        sample->ACU_PAS_ButtonPress);
    //     printf("Func_Diag_Request %lld \r\n",        sample->Func_Diag_Request);
    //     printf("TEL_PowerOnReq %d \r\n",        sample->TEL_PowerOnReq);
    //     printf("TEL_HRVPCancelParking %d \r\n",        sample->TEL_HRVPCancelParking);
    //     printf("TEL_AVPHrvpBtnStVD %d \r\n",        sample->TEL_AVPHrvpBtnStVD);
    //     printf("TEL_AVPHrvpBtnSt %d \r\n",        sample->TEL_AVPHrvpBtnSt);
    //     printf("TEL_HAVPPathSelect %d \r\n",        sample->TEL_HAVPPathSelect);
    //     printf("SBM_EngineStartReqVD %d \r\n",        sample->SBM_EngineStartReqVD);
    //     printf("SBM_EngineStartReq %d \r\n",        sample->SBM_EngineStartReq);
    //     printf("SBM_RPAResponse %d \r\n",        sample->SBM_RPAResponse);
    //     printf("SBM_HAVPPathSelect %d \r\n",        sample->SBM_HAVPPathSelect);
    //     printf("SBM_HRVPDisclaimerAgree %d \r\n",        sample->SBM_HRVPDisclaimerAgree);
    //     printf("SBM_HRVPCancelParking %d \r\n",        sample->SBM_HRVPCancelParking);
    //     printf("SBM_FingerPositionY %d \r\n",        sample->SBM_FingerPositionY);
    //     printf("SBM_FingerPositionX %d \r\n",        sample->SBM_FingerPositionX);
    //     printf("SBM_ComSDKUBouncesSt %d \r\n",        sample->SBM_ComSDKUBouncesSt);
    //     printf("SBM_InitGestureSt %d \r\n",        sample->SBM_InitGestureSt);
    //     printf("SBM_RPACancelBtnStVD %d \r\n",        sample->SBM_RPACancelBtnStVD);
    //     printf("SBM_RPACancelBtnSt %d \r\n",        sample->SBM_RPACancelBtnSt);
    //     printf("SBM_RPABtnStVD %d \r\n",        sample->SBM_RPABtnStVD);
    //     printf("SBM_RPABtnSt %d \r\n",        sample->SBM_RPABtnSt);
    //     printf("SBM_IMMOCode %d \r\n",        sample->SBM_IMMOCode);
    //     printf("SBM_ForRPAFailReason %d \r\n",        sample->SBM_ForRPAFailReason);
    //     printf("SBM_RPADeviceFailReason %d \r\n",        sample->SBM_RPADeviceFailReason);
    //     printf("SBM_RPAKeyPstSt %d \r\n",        sample->SBM_RPAKeyPstSt);
    //     printf("SBM_RPACheckReq %d \r\n",        sample->SBM_RPACheckReq);
    //     printf("SBM_PhoneBatt %d \r\n",        sample->SBM_PhoneBatt);
    //     printf("SBM_RPADeviceSt %d \r\n",        sample->SBM_RPADeviceSt);
    //     printf("SBM_RPAmode %d \r\n",        sample->SBM_RPAmode);
    //     printf("SBM_RPADirectionSel %d \r\n",        sample->SBM_RPADirectionSel);
    //     printf("ACU_HAVPMagSt %d \r\n",        sample->ACU_HAVPMagSt);
    //     printf("ACU_PAAMode %d \r\n",        sample->ACU_PAAMode);
    //     printf("ACU_VR_APA_Switch %d \r\n",        sample->ACU_VR_APA_Switch);
    //     printf("ACU_VR_SVM_Switch %d \r\n",        sample->ACU_VR_SVM_Switch);
    //     printf("ACU_HAVPPathSelect %d \r\n",        sample->ACU_HAVPPathSelect);
    //     printf("ACU_HAVPPathDelete %d \r\n",        sample->ACU_HAVPPathDelete);
    //     printf("ACU_HAVPLearningTypeSele %d \r\n",        sample->ACU_HAVPLearningTypeSele);
    //     printf("ACU_HAVPLearningSetParkLot %d \r\n",        sample->ACU_HAVPLearningSetParkLot);
    //     printf("ACU_APAParkSlotselect %d \r\n",        sample->ACU_APAParkSlotselect);
    //     printf("ACU_HAVPDisclaimerAgree %d \r\n",        sample->ACU_HAVPDisclaimerAgree);
    //     printf("ACU_APAFunctionCancelled %d \r\n",        sample->ACU_APAFunctionCancelled);
    //     printf("ACU_APASwitctSt %d \r\n",        sample->ACU_APASwitctSt);
    //     printf("ACU_HAVPSetPathSave %d \r\n",        sample->ACU_HAVPSetPathSave);
    //     printf("ACU_HAVPSetPathEnding %d \r\n",        sample->ACU_HAVPSetPathEnding);
    //     printf("ACU_HAVPLearningBackgroundRepeat %d \r\n",        sample->ACU_HAVPLearningBackgroundRepeat);
    //     printf("ACU_HAVPLearningStop %d \r\n",        sample->ACU_HAVPLearningStop);
    //     printf("ACU_HAVPLearningCancelpath %d \r\n",        sample->ACU_HAVPLearningCancelpath);
    //     printf("ACU_HAVPSetStarting %d \r\n",        sample->ACU_HAVPSetStarting);
    //     printf("ACU_HAVPConfirm %d \r\n",        sample->ACU_HAVPConfirm);
    //     printf("ACU_HAVPSwitchPressed %d \r\n",        sample->ACU_HAVPSwitchPressed);
    //     printf("ACU_HAVPCancelParking %d \r\n",        sample->ACU_HAVPCancelParking);
    //     printf("SteeringAngle_Timeus %lld \r\n",        sample->SteeringAngle_Timeus);
    //     printf("SAS_SteeringAngle %d \r\n",        sample->SAS_SteeringAngle);
    //     printf("SAS_CalibratedSt %d \r\n",        sample->SAS_CalibratedSt);
    //     printf("SAS_SteeringAngleVD %d \r\n",        sample->SAS_SteeringAngleVD);
    //     printf("EBB_BCSReqBrkPedalAppliedSt %d \r\n",        sample->EBB_BCSReqBrkPedalAppliedSt);
    //     printf("EBB_BCSReqBrkPedalApplied %d \r\n",        sample->EBB_BCSReqBrkPedalApplied);
    //     printf("BCS_HBBIntervention %d \r\n",        sample->BCS_HBBIntervention);
    //     printf("BCS_APATorqReqEV %d \r\n",        sample->BCS_APATorqReqEV);
    //     printf("BCS_APATorqReqSt %d \r\n",        sample->BCS_APATorqReqSt);
    //     printf("BCS_APAGrarLvlReqVD %d \r\n",        sample->BCS_APAGrarLvlReqVD);
    //     printf("BCS_APAGrarLvlReq %d \r\n",        sample->BCS_APAGrarLvlReq);
    //     printf("BCS_VDCActiveSt %d \r\n",        sample->BCS_VDCActiveSt);
    //     printf("BCS_VehSpd %d \r\n",        sample->BCS_VehSpd);
    //     printf("BCS_VehSpdVD %d \r\n",        sample->BCS_VehSpdVD);
    //     printf("BCS_VDCFaultSt %d \r\n",        sample->BCS_VDCFaultSt);
    //     printf("BCS_TCSActiveSt %d \r\n",        sample->BCS_TCSActiveSt);
    //     printf("BCS_TCSFaultSt %d \r\n",        sample->BCS_TCSFaultSt);
    //     printf("BCS_EBDActiveSt %d \r\n",        sample->BCS_EBDActiveSt);
    //     printf("BCS_EBDFaultSt %d \r\n",        sample->BCS_EBDFaultSt);
    //     printf("BCS_ABSFaultSt %d \r\n",        sample->BCS_ABSFaultSt);
    //     printf("BCS_ABSActiveSt %d \r\n",        sample->BCS_ABSActiveSt);
    //     printf("VCU_VehRdySt %d \r\n",        sample->VCU_VehRdySt);
    //     printf("FRR_FCTAWarnR %d \r\n",        sample->FRR_FCTAWarnR);
    //     printf("FRR_FCTAWarnL %d \r\n",        sample->FRR_FCTAWarnL);
    //     printf("ADAS_HWAHF_SafeStop %d \r\n",        sample->ADAS_HWAHF_SafeStop);
    //     printf("ADAS_HWAHF_TakeOverReq %d \r\n",        sample->ADAS_HWAHF_TakeOverReq);
    //     printf("ADAS_HWA_ILCRighttSt %d \r\n",        sample->ADAS_HWA_ILCRighttSt);
    //     printf("ADAS_HWA_ILCLeftSt %d \r\n",        sample->ADAS_HWA_ILCLeftSt);
    //     printf("SRS_DriverSeatBeltSt %d \r\n",        sample->SRS_DriverSeatBeltSt);
    //     printf("SRS_PsngrSeatBeltSt %d \r\n",        sample->SRS_PsngrSeatBeltSt);
    //     printf("ICM_TotalOdometer %lld \r\n",        sample->ICM_TotalOdometer);
    //     printf("HVAC_CorrectedExterTemp %d \r\n",        sample->HVAC_CorrectedExterTemp);
    //     printf("HVAC_CorrectedExterTempVD %d \r\n",        sample->HVAC_CorrectedExterTempVD);
    //     printf("TEL_AVPDeviceSt %d \r\n",        sample->TEL_AVPDeviceSt);
    //     printf("TEL_ErrStToAVP %d \r\n",        sample->TEL_ErrStToAVP);
    //     printf("SBM_Phone_Connectingst %d \r\n",        sample->SBM_Phone_Connectingst);
    //     printf("PEPS_PsgSeatSts %d \r\n",        sample->PEPS_PsgSeatSts);
    //     printf("PEPS_Driverseatstatus %d \r\n",        sample->PEPS_Driverseatstatus);
    //     printf("PEPS_PowerKeepSts %d \r\n",        sample->PEPS_PowerKeepSts);
    //     printf("PEPS_RPAState %d \r\n",        sample->PEPS_RPAState);
    //     printf("PEPS_TelePowMode %d \r\n",        sample->PEPS_TelePowMode);
    //     printf("IPS_DCDCModeSt %d \r\n",        sample->IPS_DCDCModeSt);
    //     printf("BMS_DcChargerSt %d \r\n",        sample->BMS_DcChargerSt);
    //     printf("IPS_OBCCC_St %d \r\n",        sample->IPS_OBCCC_St);
    //     printf("FRDCM_MirrorFoldUnfoldSt %d \r\n",        sample->FRDCM_MirrorFoldUnfoldSt);
    //     printf("FRDCM_RRWinSt %d \r\n",        sample->FRDCM_RRWinSt);
    //     printf("FRDCM_FRWinSt %d \r\n",        sample->FRDCM_FRWinSt);
    //     printf("FLDCM_MirrorFoldUnfoldSt %d \r\n",        sample->FLDCM_MirrorFoldUnfoldSt);
    //     printf("FLDCM_MirrorFoldUnfoldSwitchSt %d \r\n",        sample->FLDCM_MirrorFoldUnfoldSwitchSt);
    //     printf("FLDCM_RLWinSt %d \r\n",        sample->FLDCM_RLWinSt);
    //     printf("FLDCM_FLWinSt %d \r\n",        sample->FLDCM_FLWinSt);
    //     printf("TPMS_TyreSt %d \r\n",        sample->TPMS_TyreSt);
    //     printf("BCM_BrakeLightFaultSt %d \r\n",        sample->BCM_BrakeLightFaultSt);
    //     printf("BCM_BrakeLightSt %d \r\n",        sample->BCM_BrakeLightSt);
    //     printf("BCM_ReverseLightSt %d \r\n",        sample->BCM_ReverseLightSt);
    //     printf("BCM_HazardLampSt %d \r\n",        sample->BCM_HazardLampSt);
    //     printf("VCU_EMS_BrkPedalStVD %d \r\n",        sample->VCU_EMS_BrkPedalStVD);
    //     printf("VCU_EMS_BrkPedalSt %d \r\n",        sample->VCU_EMS_BrkPedalSt);
    //     printf("EMS_GasPedalActPstforMRR %d \r\n",        sample->EMS_GasPedalActPstforMRR);
    //     printf("EMS_GasPedalActPstforMRRVD %d \r\n",        sample->EMS_GasPedalActPstforMRRVD);
    //     printf("VCU_VehWheelTorqMax %d \r\n",        sample->VCU_VehWheelTorqMax);
    //     printf("VCU_ActVehWheelTorq %d \r\n",        sample->VCU_ActVehWheelTorq);
    //     printf("VCU_APAGearIntervern %d \r\n",        sample->VCU_APAGearIntervern);
    //     printf("VCU_APA_Resp %d \r\n",        sample->VCU_APA_Resp);
    //     printf("VCU_APAWheelTorqDriverReq %d \r\n",        sample->VCU_APAWheelTorqDriverReq);
    //     printf("VCU_APAAvailable %d \r\n",        sample->VCU_APAAvailable);
    //     printf("VCU_CrntGearLvl %d \r\n",        sample->VCU_CrntGearLvl);
    //     printf("MRR_ABPReq %d \r\n",        sample->MRR_ABPReq);
    //     printf("MRR_AEBDecelCtrlReq %d \r\n",        sample->MRR_AEBDecelCtrlReq);
    //     printf("ADAS_LongCtrlModeForBrkSys %d \r\n",        sample->ADAS_LongCtrlModeForBrkSys);
    //     printf("MRR_FCWPreWarn %d \r\n",        sample->MRR_FCWPreWarn);
    //     printf("SRS_CrashOutputSt %d \r\n",        sample->SRS_CrashOutputSt);
    //     printf("BCM_PsngrDoorLockSt %d \r\n",        sample->BCM_PsngrDoorLockSt);
    //     printf("BCM_DriverDoorLockSt %d \r\n",        sample->BCM_DriverDoorLockSt);
    //     printf("BCM_AutoHighBeamCtrlSt %d \r\n",        sample->BCM_AutoHighBeamCtrlSt);
    //     printf("BCM_ATWS_St %d \r\n",        sample->BCM_ATWS_St);
    //     printf("BCM_VehReverseSt %d \r\n",        sample->BCM_VehReverseSt);
    //     printf("BCM_ParkingLampSt %d \r\n",        sample->BCM_ParkingLampSt);
    //     printf("BCM_RightTurnLampFaultSt %d \r\n",        sample->BCM_RightTurnLampFaultSt);
    //     printf("BCM_RightTurnLampSt %d \r\n",        sample->BCM_RightTurnLampSt);
    //     printf("BCM_LeftTurnLampFaultSt %d \r\n",        sample->BCM_LeftTurnLampFaultSt);
    //     printf("BCM_LeftTurnLampSt %d \r\n",        sample->BCM_LeftTurnLampSt);
    //     printf("BCM_TurnLightSwitchSt %d \r\n",        sample->BCM_TurnLightSwitchSt);
    //     printf("BCM_RRDoorAjarSt %d \r\n",        sample->BCM_RRDoorAjarSt);
    //     printf("BCM_RLDoorAjarSt %d \r\n",        sample->BCM_RLDoorAjarSt);
    //     printf("BCM_PsngrDoorAjarSt %d \r\n",        sample->BCM_PsngrDoorAjarSt);
    //     printf("BCM_TrunkAjarSt %d \r\n",        sample->BCM_TrunkAjarSt);
    //     printf("BCM_BrakeLightSwitchSt %d \r\n",        sample->BCM_BrakeLightSwitchSt);
    //     printf("BCM_DriverDoorAjarSt %d \r\n",        sample->BCM_DriverDoorAjarSt);
    //     printf("BCM_ReverseSwitchSt %d \r\n",        sample->BCM_ReverseSwitchSt);
    //     printf("BCM_KeySt %d \r\n",        sample->BCM_KeySt);
    //     printf("BCM_ReverseSwitchStVD %d \r\n",        sample->BCM_ReverseSwitchStVD);
    //     printf("BCM_HighBeamSt %d \r\n",        sample->BCM_HighBeamSt);
    //     printf("BCM_LowBeamSt %d \r\n",        sample->BCM_LowBeamSt);
    //     printf("EPS_PAS_AbortFeedback %d \r\n",        sample->EPS_PAS_AbortFeedback);
    //     printf("EPS_PAS_ReqFeedback %d \r\n",        sample->EPS_PAS_ReqFeedback);
    //     printf("EPS_PAS_EpasFailed %d \r\n",        sample->EPS_PAS_EpasFailed);
    //     printf("EPS_StrngWhlTorq %d \r\n",        sample->EPS_StrngWhlTorq);
    //     printf("EPS_StrngWhlTorqVD %d \r\n",        sample->EPS_StrngWhlTorqVD);
    //     printf("EPB_FailSt %d \r\n",        sample->EPB_FailSt);
    //     printf("EPB_SysSt %d \r\n",        sample->EPB_SysSt);
    //     printf("BCS_ActVehLaltrlAccelVD %d \r\n",        sample->BCS_ActVehLaltrlAccelVD);
    //     printf("BCS_ActVehLongAccelVD %d \r\n",        sample->BCS_ActVehLongAccelVD);
    //     printf("BCS_VehLaltrlAccelOffset %d \r\n",        sample->BCS_VehLaltrlAccelOffset);
    //     printf("BCS_ActVehLaltrlAccel %d \r\n",        sample->BCS_ActVehLaltrlAccel);
    //     printf("BCS_VehLongAccelOffset %d \r\n",        sample->BCS_VehLongAccelOffset);
    //     printf("BCS_ActVehLongAccel %d \r\n",        sample->BCS_ActVehLongAccel);
    //     printf("BCS_LSM23Avl %d \r\n",        sample->BCS_LSM23Avl);
    //     printf("BCS_LSM12EmergencyAvl %d \r\n",        sample->BCS_LSM12EmergencyAvl);
    //     printf("R_WheelRotatedDirectionAPA_Timeus %lld \r\n",        sample->R_WheelRotatedDirectionAPA_Timeus);
    //     printf("BCS_RRWheelRotatedDirectionAPA %d \r\n",        sample->BCS_RRWheelRotatedDirectionAPA);
    //     printf("BCS_RLWheelRotatedDirectionAPA %d \r\n",        sample->BCS_RLWheelRotatedDirectionAPA);
    //     printf("BCS_LSM12ComfortAvl %d \r\n",        sample->BCS_LSM12ComfortAvl);
    //     printf("BCS_LSMSubMTLongEcho %d \r\n",        sample->BCS_LSMSubMTLongEcho);
    //     printf("BCS_RRWheelSpd %d \r\n",        sample->BCS_RRWheelSpd);
    //     printf("BCS_RRWheelSpdVD %d \r\n",        sample->BCS_RRWheelSpdVD);
    //     printf("BCS_RRWheelRotatedDirectionVD %d \r\n",        sample->BCS_RRWheelRotatedDirectionVD);
    //     printf("BCS_RLWheelSpd %d \r\n",        sample->BCS_RLWheelSpd);
    //     printf("BCS_LSMSubMTReqAvailable %d \r\n",        sample->BCS_LSMSubMTReqAvailable);
    //     printf("BCS_LSMSubMTLevelEcho %d \r\n",        sample->BCS_LSMSubMTLevelEcho);
    //     printf("BCS_RLWheelRotatedDirectionVD %d \r\n",        sample->BCS_RLWheelRotatedDirectionVD);
    //     printf("BCS_RLWheelSpdVD %d \r\n",        sample->BCS_RLWheelSpdVD);
    //     printf("BCS_CDDAPVehHoldActive %d \r\n",        sample->BCS_CDDAPVehHoldActive);
    //     printf("BCS_LSMSubMTReqEcho %d \r\n",        sample->BCS_LSMSubMTReqEcho);
    //     printf("BCS_LSMPosLongACapbl %d \r\n",        sample->BCS_LSMPosLongACapbl);
    //     printf("F_WheelRotatedDirectionAPA_Timeus %lld \r\n",        sample->F_WheelRotatedDirectionAPA_Timeus);
    //     printf("BCS_FRWheelRotatedDirectionAPA %d \r\n",        sample->BCS_FRWheelRotatedDirectionAPA);
    //     printf("BCS_FLWheelRotatedDirectionAPA %d \r\n",        sample->BCS_FLWheelRotatedDirectionAPA);
    //     printf("BCS_FRWheelSpd %d \r\n",        sample->BCS_FRWheelSpd);
    //     printf("BCS_FRWheelSpdVD %d \r\n",        sample->BCS_FRWheelSpdVD);
    //     printf("BCS_FRWheelRotatedDirectionVD %d \r\n",        sample->BCS_FRWheelRotatedDirectionVD);
    //     printf("BCS_FLWheelSpd %d \r\n",        sample->BCS_FLWheelSpd);
    //     printf("BCS_FLWheelRotatedDirectionVD %d \r\n",        sample->BCS_FLWheelRotatedDirectionVD);
    //     printf("BCS_FLWheelSpdVD %d \r\n",        sample->BCS_FLWheelSpdVD);
    //     printf("BCS_HHCCtrlSt %d \r\n",        sample->BCS_HHCCtrlSt);
    //     printf("YawRate_Timeus %lld \r\n",        sample->YawRate_Timeus);
    //     printf("BCS_YawRateOffset %d \r\n",        sample->BCS_YawRateOffset);
    //     printf("BCS_YawRate %d \r\n",        sample->BCS_YawRate);
    //     printf("BCS_YawRateSt %d \r\n",        sample->BCS_YawRateSt);
    //     printf("BCS_RRWheelSpdEdgesSumVD %d \r\n",        sample->BCS_RRWheelSpdEdgesSumVD);
    //     printf("BCS_RLWheelSpdEdgesSumVD %d \r\n",        sample->BCS_RLWheelSpdEdgesSumVD);
    //     printf("BCS_FRWheelSpdEdgesSumVD %d \r\n",        sample->BCS_FRWheelSpdEdgesSumVD);
    //     printf("BCS_FLWheelSpdEdgesSumVD %d \r\n",        sample->BCS_FLWheelSpdEdgesSumVD);
    //     printf("WheelSpdEdgesSum_Timeus %lld \r\n",        sample->WheelSpdEdgesSum_Timeus);
    //     printf("BCS_RRWheelSpdEdgesSum %d \r\n",        sample->BCS_RRWheelSpdEdgesSum);
    //     printf("BCS_RLWheelSpdEdgesSum %d \r\n",        sample->BCS_RLWheelSpdEdgesSum);
    //     printf("BCS_FRWheelSpdEdgesSum %d \r\n",        sample->BCS_FRWheelSpdEdgesSum);
    //     printf("BCS_FLWheelSpdEdgesSum %d \r\n",        sample->BCS_FLWheelSpdEdgesSum);
    //     printf("BCM_BonnetAjarSt %d \r\n",        sample->BCM_BonnetAjarSt);
    //     printf("BCM_FrontWiperSt %d \r\n",        sample->BCM_FrontWiperSt);
    //     printf("BSDM_RCTAWarnRight %d \r\n",        sample->BSDM_RCTAWarnRight);
    //     printf("BSDS_RCTAWarnLeft %d \r\n",        sample->BSDS_RCTAWarnLeft);
    //     printf("sub ACU_VR_APA_Switch: %d \r\n", sample->ACU_VR_APA_Switch);
    // }
}




