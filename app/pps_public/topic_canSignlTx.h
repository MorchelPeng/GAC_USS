#ifndef TOPIC_CAN_SIGNAL_TX_H
#define TOPIC_CAN_SIGNAL_TX_H

#include "ppscontrol.h"
#include "app_pps_protocal.h"

class TopicCanSignalTx
{
public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub)
    {
        DESY::PPS_CFG_STRU cfg={TOPICID_CANSIG_TX_FAST_APP,"canSignalTxFast",16,issub,ispub,15,300};
        return cfg;
    }
};

typedef enum
{
    CMDID_CAN_SIGNAL_TX_FAST	= 0, //DesayInterface_pps_canSignal_txFast
    CMDID_CAN_SIGNAL_TX_20MS    = 1,
    CMDID_CAN_SIGNAL_TX_EVENT_0B3 = 2,
    CMDID_CAN_SIGNAL_TX_EVENT_09D = 3,
    CMDID_CAN_SIGNAL_TX_FAST_MAX
} CMDID_IN_CAN_SIGNAL_TX_FAST_ENUM;

//IdtCanSignalTxRoute100ms;IdtCanSignalTxRoute100ms//DesayInterface_pps_canSignal_txFast
class DesayInterface_pps_canSignal_txFast
{
public:
    DEY_UnsignedLongLong MCU1Timeus;
    DEY_UnsignedLongLong MCU3RTimeus;
    DEY_UnsignedLongLong MCU3STimeus;
    DEY_UnsignedLongLong MCUSocTimeus;
    DEY_Octet PCS_MirrorPageDownButtonST;
    DEY_Octet PCS_SystemSt;
    DEY_Octet PCS_VRSwitch_FailSt;
    DEY_Octet PCS_CalibrateSt;
    DEY_Octet PCS_EventRecordSt;
    DEY_Octet PCS_HMIIndex;
    DEY_Octet PCS_VoiceReq;
    DEY_Octet PCS_OperationSt;
    DEY_Octet PCS_APA_BackParkButton;
    DEY_Octet PCS_APATurnLampReq;
    DEY_Octet PCS_APASlotActiveSt;
    DEY_Octet PCS_HelpMenuSt;
    DEY_Octet PCS_ACU_DisplayReq;
    DEY_Octet PCS_ER_EnterConfirm;
    DEY_Octet PCS_ER_QuitReq;
    DEY_Octet PAS_ButtonPress;
    DEY_Octet PAS_RRMidDistance;
    DEY_Octet PAS_RLMidDistance;
    DEY_Octet PAS_RRDistance;
    DEY_Octet PAS_RLDistance;
    DEY_Octet PAS_RSLSideDistance;
    DEY_Octet PAS_RSRSideDistance;
    DEY_Octet PAS_FRDistance;
    DEY_Octet PAS_FLDistance;
    DEY_Octet PAS_FRMidDistance;
    DEY_Octet PAS_FLMidDistance;
    DEY_Octet PAS_FSRSideDistance;
    DEY_Octet PAS_FSLSideDistance;
    DEY_Octet PAS_RRMidSnsErrFlag;
    DEY_Octet PAS_RLMidSnsErrFlag;
    DEY_Octet PAS_RRSnsErrFlag;
    DEY_Octet PAS_RLSnsErrFlag;
    DEY_Octet PAS_RSLSnsErrFlag;
    DEY_Octet PAS_RSRSnsErrFlag;
    DEY_Octet PAS_FRSnsErrFlag;
    DEY_Octet PAS_FLSnsErrFlag;
    DEY_Octet PAS_FRMidSnsErrFlag;
    DEY_Octet PAS_FLMidSnsErrFlag;
    DEY_Octet PAS_FSLSnsErrFlag;
    DEY_Octet PAS_FSRSnsErrFlag;
    DEY_Octet PAS_CtrlModulerrFlag;
    DEY_Octet PAS_BattVoltErrFlag;
    DEY_Octet FAPA_IGOffReqEnable;
    DEY_Octet FAPA_VideoSt;
    //DEY_Octet PAS_RAEBWorkSts;
    DEY_Octet PAS_EngSSInhibitSt;
    DEY_Octet PAS_IGCInhibitSt;
    DEY_Octet AVP_LearningPathNum1;
    DEY_Octet AVP_HAVPPathLearnRate1;
    DEY_Octet AVP_LearningPathType1;
    DEY_Octet AVP_LearningLotType1;
    DEY_Octet AVP_HAVPPathSt1;
    DEY_Octet AVP_HAVPPath1Src;
    DEY_Octet AVP_HAVPPathDst1;
    DEY_Octet AVP_LearningPathNum2;
    DEY_Octet AVP_HAVPPathLearnRate2;
    DEY_Octet AVP_LearningPathType2;
    DEY_Octet AVP_LearningLotType2;
    DEY_Octet AVP_HAVPPathSt2;
    DEY_Octet AVP_HAVPPath2Src;
    DEY_Octet AVP_HAVPPathDst2;
    DEY_Octet AVP_HAVPPath1MatGpsSucces;
    DEY_Octet AVP_HAVPPath2MatGpsSucces;
    DEY_Octet AVP_LrngDst;
    DEY_Octet AVP_LearningPathNum3;
    DEY_Octet AVP_HAVPPathLearnRate3;
    DEY_Octet AVP_LearningPathType3;
    DEY_Octet AVP_LearningLotType3;
    DEY_Octet AVP_HAVPPathSt3;
    DEY_Octet AVP_HAVPPath3Src;
    DEY_Octet AVP_HAVPPathDst3;
    DEY_Octet AVP_LearningPathNum4;
    DEY_Octet AVP_HAVPPathLearnRate4;
    DEY_Octet AVP_LearningPathType4;
    DEY_Octet AVP_LearningLotType4;
    DEY_Octet AVP_HAVPPathSt4;
    DEY_Octet AVP_HAVPPath4Src;
    DEY_Octet AVP_HAVPPathDst4;
    DEY_Octet AVP_HAVPPath3MatGpsSucces;
    DEY_Octet AVP_HAVPPath4MatGpsSucces;
    DEY_Octet AVP_HAVPResRouteLeg;
    DEY_Octet AVP_LearningPathNum5;
    DEY_Octet AVP_HAVPPathLearnRate5;
    DEY_Octet AVP_LearningPathType5;
    DEY_Octet AVP_LearningLotType5;
    DEY_Octet AVP_HAVPPathSt5;
    DEY_Octet AVP_HAVPPath5Src;
    DEY_Octet AVP_HAVPPathDst5;
    DEY_Octet AVP_LearningPathNum6;
    DEY_Octet AVP_HAVPPathLearnRate6;
    DEY_Octet AVP_LearningPathType6;
    DEY_Octet AVP_LearningLotType6;
    DEY_Octet AVP_HAVPPathSt6;
    DEY_Octet AVP_HAVPPath6Src;
    DEY_Octet AVP_HAVPPathDst6;
    DEY_Octet AVP_HAVPPath5MatGpsSucces;
    DEY_Octet AVP_HAVPPath6MatGpsSucces;
    DEY_Octet AVP_HAVPUseActDis;
    DEY_Octet AVP_LearningPathNum7;
    DEY_Octet AVP_HAVPPathLearnRate7;
    DEY_Octet AVP_LearningPathType7;
    DEY_Octet AVP_LearningLotType7;
    DEY_Octet AVP_HAVPPathSt7;
    DEY_Octet AVP_HAVPPath7Src;
    DEY_Octet AVP_HAVPPathDst7;
    DEY_Octet AVP_LearningPathNum8;
    DEY_Octet AVP_HAVPPathLearnRate8;
    DEY_Octet AVP_LearningPathType8;
    DEY_Octet AVP_LearningLotType8;
    DEY_Octet AVP_HAVPPathSt8;
    DEY_Octet AVP_HAVPPath8Src;
    DEY_Octet AVP_HAVPPathDst8;
    DEY_Octet AVP_HAVPPath7MatGpsSucces;
    DEY_Octet AVP_HAVPPath8MatGpsSucces;
    DEY_Octet AVP_HAVPProcRat;
    DEY_Octet AVP_LearningPathNum9;
    DEY_Octet AVP_HAVPPathLearnRate9;
    DEY_Octet AVP_LearningPathType9;
    DEY_Octet AVP_LearningLotType9;
    DEY_Octet AVP_HAVPPathSt9;
    DEY_Octet AVP_HAVPPath9Src;
    DEY_Octet AVP_HAVPPathDst9;
    DEY_Octet AVP_LearningPathNum10;
    DEY_Octet AVP_HAVPPathLearnRate10;
    DEY_Octet AVP_LearningPathType10;
    DEY_Octet AVP_LearningLotType10;
    DEY_Octet AVP_HAVPPathSt10;
    DEY_Octet AVP_HAVPPath10Src;
    DEY_Octet AVP_HAVPPathDst10;
    DEY_Octet AVP_HAVPPath9MatGpsSucces;
    DEY_Octet AVP_HAVPPath10MatGpsSucces;
     //20220316 由A72划到MCU3-0APP 发送
    // DEY_Octet AVP_FctSt;
    // DEY_Octet AVP_St;
    DEY_Octet AVP_RecInd;
    DEY_Octet AVP_HAVPCtrlSigSrc;
    DEY_Octet AVP_QuitInd;
    DEY_Octet AVP_DrvReq;
    DEY_UnsignedShort AVP_HAVPUseTolTime;
 };

 class DesayInterface_pps_IdtCanSignalTxRoute20ms{
public:
    DEY_UnsignedLongLong MCU1Timeus;
    DEY_UnsignedLongLong MCU3RTimeus;
    DEY_UnsignedLongLong MCU3STimeus;
    DEY_UnsignedLongLong MCUSocTimeus;
    DEY_Octet PAS_Mode;
 };

class DesayInterface_pps_IdtCanSignalTxRouteEvent_0B3{
public:
    DEY_Octet APA_ViceRmindrWaitResp;
};

class DesayInterface_pps_IdtCanSignalTxRouteEvent_09D{
public:    
    DEY_Octet PAA_Challenge1TEL;
    DEY_Octet PAA_Challenge2TEL;
    DEY_Octet PAA_ChallengeReceive;
};


#endif
