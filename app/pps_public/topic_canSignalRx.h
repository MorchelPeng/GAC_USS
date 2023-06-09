#ifndef TOPIC_CANSIGNALRX_H
#define TOPIC_CANSIGNALRX_H

#include "ppscontrol.h"
#include "app_pps_protocal.h"

class TopicCanSignalRx
{
public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub)
    {
        DESY::PPS_CFG_STRU cfg={TOPICID_CANSIGNAL_RX_APP,"topcid_gac_can_rx",16,issub,ispub,15,300};
        return cfg;
    }
};

typedef enum
{
    CMDID_CAN_SIGNAL_RX_EVENT	= 0, //DesayInterface_pps_IdtCanSignalRxRouteEvent
    // CMDID_CAN_SIGNAL_RX_10MS    = 1,//DesayInterface_pps_IdtCanSignalRxRoute10ms
    CMDID_CAN_SIGNAL_RX_20MS    = 1,//DesayInterface_pps_IdtCanSignalRxRoute20ms
    CMDID_CAN_SIGNAL_RX_100MS    = 2,//DesayInterface_pps_IdtCanSignalRxRoute100ms
    CMDID_CAN_SIGNAL_RX_500MS   = 3, //DesayInterface_pps_IdtCanSignalRxRoute500ms
    CMDID_CAN_SIGNAL_RX_MAX,
} CMDID_IN_CAN_SIGNAL_RX_ENUM;

//IdtCanSignalRxRouteEvent;
class DesayInterface_pps_IdtCanSignalRxRouteEvent {
public:
    DEY_Octet WarnTone_ButtonPress;
    DEY_Octet ScreenTouchSt;
    DEY_Octet CurrentSceenSt;
    DEY_UnsignedShort ScreenCoordY;
    DEY_UnsignedShort ScreenCoordX;
    DEY_Octet SVM_VRSwitch;
    DEY_Octet SVM_ButtonPress;

};

class DesayInterface_pps_IdtCanSignalRxRoute10ms {
public:
    DEY_UnsignedLongLong MCU1RTimeus;
    DEY_UnsignedLongLong MCU1STimeus;
    DEY_UnsignedLongLong MCU3RTimeus;
    DEY_UnsignedLongLong MCU3STimeus;
    DEY_UnsignedLongLong MCUSocTimeus;
    DEY_Octet BCS_ABSActiveSt;
    DEY_Octet BCS_ABSFaultSt;
    DEY_Octet BCS_EBDFaultSt;
    DEY_Octet BCS_EBDActiveSt;
    DEY_Octet BCS_TCSFaultSt;
    DEY_Octet BCS_TCSActiveSt;
    DEY_Octet BCS_VDCFaultSt;
    DEY_Octet BCS_VehSpdVD;
    DEY_UnsignedShort BCS_VehSpd;
    DEY_Octet BCS_VDCActiveSt;
    DEY_Octet SAS_SteeringAngleVD;
    DEY_Octet SAS_CalibratedSt;
    DEY_UnsignedShort SAS_SteeringAngle;
    DEY_Octet TCU_GearForDisp;
    DEY_Octet TCU_CurrentGearSt;
    DEY_Octet TCU_CurrentGearStVD;
    DEY_Octet EMS_GasPedalActPst;
    DEY_Octet EMS_GasPedalActPstVD;
    DEY_Octet EMS_BrakePedalStVD;
    DEY_Octet EMS_BrakePedalSt;
    DEY_Octet EMS_EngSt;
    DEY_Octet EMS_GasPedalActPstforMRRVD;
    DEY_Octet EMS_GasPedalActPstforMRR;
    DEY_Octet EMS_MaxEngTorqNorm;
    DEY_Octet EMS_ClutchTorqDriverReqVD;
    DEY_Octet EMS_ClutchTorqVD;
    DEY_Octet EMS_EngFrictionTorqVD;
    DEY_Octet EMS_ClutchTorq;
    DEY_Octet EMS_ClutchTorqDriverReq;
    DEY_Octet EMS_EngFrictionTorq;
    DEY_Octet EMS_MinClutchTorq;
    DEY_Octet EMS_MaxClutchTorq;
    DEY_Octet EMS_MaxClutchTorqVD;
    DEY_Octet EMS_MinClutchTorqVD;

};

class DesayInterface_pps_IdtCanSignalRxRoute20ms
{
public:
    DEY_Octet	VehSpdVD;
    DEY_Float	VehSpd;
    DEY_Octet	SteeringAngleVD;
    DEY_Octet	SteAngSen_CalibratedSt;
    DEY_Float	SteeringAngle;
    DEY_Octet	CurrentGearSt;
    DEY_Octet	CurrentGearStVD;
    DEY_Octet	FLWheelSpdVD;
    DEY_Octet	FLWheelRotatedDirection;
    DEY_Octet	FLWheelRotatedDirectionVD;
    DEY_Float	FLWheelSpd;
    DEY_Octet	FRWheelRotatedDirectionVD;
    DEY_Octet	FRWheelRotatedDirection;
    DEY_Octet	FRWheelSpdVD;
    DEY_Float	FRWheelSpd;
    DEY_Octet	FLWheelRotatedDirectionAPA;
    DEY_Octet	FRWheelRotatedDirectionAPA;
    DEY_Octet	PreVDCActiveSt;
    DEY_Octet	RLWheelSpdVD;
    DEY_Octet	RLWheelRotatedDirection;
    DEY_Octet	RLWheelRotatedDirectionVD;
    DEY_Float	RLWheelSpd;
    DEY_Octet	RRWheelRotatedDirectionVD;
    DEY_Octet	RRWheelRotatedDirection;
    DEY_Octet	RRWheelSpdVD;
    DEY_Float	RRWheelSpd;
    DEY_Octet	RLWheelRotatedDirectionAPA;
    DEY_Octet	RRWheelRotatedDirectionAPA;

};

class DesayInterface_pps_IdtCanSignalRxRoute100ms{
public:
    DEY_Octet	LowBeamSt;
    DEY_Octet	HighBeamSt;
    DEY_Octet	VehKeySt;
    DEY_Octet	BonnetAjarSt;
    DEY_Octet	ReverseSwitchSt;
    DEY_Octet	DriverDoorAjarSt;
    DEY_Octet	BrakeLightSwitchSt;
    DEY_Octet	TrunkAjarSt;
    DEY_Octet	PsngrDoorAjarSt;
    DEY_Octet	RLDoorAjarSt;
    DEY_Octet	RRDoorAjarSt;
    DEY_Octet	LeftTurnLampSt;
    DEY_Octet	LeftTurnLampFaultSt;
    DEY_Octet	RightTurnLampSt;
    DEY_Octet	RightTurnLampFaultSt;
    DEY_Octet	TurnLightSwitchSt;
    DEY_Octet	HazardLampSt;
    DEY_Octet	ReverseLightSt;
    DEY_Octet	BrakeLightSt;
    DEY_Octet	BrakeLightFaultSt;
};



class DesayInterface_pps_IdtCanSignalRxRoute500ms{
public:
    DEY_UnsignedLongLong MCU1RTimeus;
    DEY_UnsignedLongLong MCU1STimeus;
    DEY_UnsignedLongLong MCU3RTimeus;
    DEY_UnsignedLongLong MCU3STimeus;
    DEY_UnsignedLongLong MCUSocTimeus;
    DEY_Octet ACU_Time_Year;
    DEY_Octet ACU_Time_Month;
    DEY_Octet ACU_Time_Hour;
    DEY_Octet ACU_Time_Day;
    DEY_Octet ACU_Time_Min;
    DEY_Octet ACU_LanguageTypeSet;
    DEY_Octet ACU_Time_Sec;
    DEY_Octet ACU_ThemeType;
    DEY_Octet RLS_RainfallLevel;
    DEY_Octet PEPS_WELQuitReason;
    DEY_Octet PEPS_APUQuitReason;
    DEY_Octet PEPS_WALQuitReason;
    DEY_Octet PEPS_SATOQuitReason;
    //new add0302

    DEY_UnsignedLong TEL_Longitude;
    DEY_UnsignedLong TEL_Latitude;
    DEY_Octet TEL_NaviPstVD;
    DEY_Octet ACU_AUID;
    DEY_Octet TEL_NetworkMode;
    DEY_Octet TEL_SignalStrength;
    DEY_Octet TEL_GPSState;
    DEY_Octet TEL_SatelliteNum;
};


#endif
